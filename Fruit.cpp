#include "Fruit.h"
#include <cstdlib> //to generate random number ,so we use this library/header file.
Fruit::Fruit(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;
    m_Texture.loadFromFile("images/fruit.png");
    m_Shape.setSize(Vector2f(100,100));
    m_Shape.setTexture(&m_Texture);
    m_Shape.setPosition(m_Position);
}
FloatRect Fruit::getPosition() {
    return m_Shape.getGlobalBounds();
}
RectangleShape Fruit::getShape() {
    return m_Shape;
}
void Fruit::update(Time dt) {
    m_Position.y += m_Speed * dt.asSeconds();
    m_Shape.setPosition(m_Position);
}
void Fruit::resetPosition() {
    m_Position.x = rand() % 900 + 30;
    m_Position.y = 0;
}
