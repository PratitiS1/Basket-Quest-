#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Basket {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    Texture m_Texture;
    float m_Speed = 600.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft = false;
public:
    Basket(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void reset(float startX, float startY);
    void update(Time dt);
};

