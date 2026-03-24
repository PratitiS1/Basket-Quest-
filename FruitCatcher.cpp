#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Basket.h"
#include "Fruit.h"

using namespace sf;

int main() {
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Basket Quest!!!");

    int score = 0;
    int lives = 3;
    bool isGameOver = false;

Texture textureBackground;
textureBackground.loadFromFile("images/background.png");
Sprite spriteBackground;
spriteBackground.setTexture(textureBackground);
spriteBackground.setPosition(0,0);

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    Text hud;
    hud.setFont(font);
    hud.setCharacterSize(40);
    hud.setPosition(20, 20);

    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(40);
    gameOverText.setString("Press Enter to Restart");
    gameOverText.setFillColor(Color::Black);
    FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
    gameOverText.setPosition(960 / 2.0f, 540 / 2.0f);

    Basket basket(960 / 2, 540 - 80);
    Fruit fruit(rand() % 900 + 30, 0);

    Clock clock;
    SoundBuffer catchBuffer;
catchBuffer.loadFromFile("sounds/chop.wav");
Sound catchSound;
catchSound.setBuffer(catchBuffer);

SoundBuffer missBuffer;
missBuffer.loadFromFile("sounds/miss.wav");
Sound missSound;
missSound.setBuffer(missBuffer);

SoundBuffer goBuffer;
goBuffer.loadFromFile("sounds/game_over.wav");
Sound game_overSound;
game_overSound.setBuffer(goBuffer);

// input handling
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

        if (!isGameOver) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) basket.moveLeft();
            else basket.stopLeft();

            if (Keyboard::isKeyPressed(Keyboard::Right)) basket.moveRight();
            else basket.stopRight();

            // Update section
            Time dt = clock.restart();
            basket.update(dt);
            fruit.update(dt);

            // Collision with basket
            if (fruit.getPosition().intersects(basket.getPosition())) {
                score++;
                fruit.resetPosition();
                catchSound.play();

            }

            // Missed fruit
            if (fruit.getPosition().top > window.getSize().y) {
                lives--;
                fruit.resetPosition();
                missSound.play();
                if (lives == 0) {
                    isGameOver = true;
                    game_overSound.play();

                }
            }

            std::stringstream ss;
            ss<< "Score: "<< score<< " Lives: " << lives;
            hud.setString(ss.str());
        } else {
            // Restart game on Enter key
            if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                score = 0;
                lives = 3;
                isGameOver = false;
                basket.reset(960 / 2, 540 - 80);
                fruit.resetPosition();
                clock.restart();  // Reset time if can't add then right after the game is restart ,it will restart with the miss sound.

                
            }
        }

        // Draw the scene
        window.clear();
        window.draw(spriteBackground);
        window.draw(hud);
        window.draw(basket.getShape());
        window.draw(fruit.getShape());
        if (isGameOver) {
            window.draw(gameOverText);
        }
        window.display();
    }

    return 0;
}
