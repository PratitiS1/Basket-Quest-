#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Fruit {
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    Texture m_Texture;
    float m_Speed = 450.0f;
public:
    Fruit(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void update(Time dt);
    void resetPosition();
};
