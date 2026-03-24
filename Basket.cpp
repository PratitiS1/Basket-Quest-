#include "Basket.h"
Basket::Basket(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;
    m_Texture.loadFromFile("images/basket.png");
    m_Shape.setSize(Vector2f(230, 100));
    m_Shape.setTexture(&m_Texture);
    m_Shape.setPosition(m_Position);
}
FloatRect Basket::getPosition() {
    return m_Shape.getGlobalBounds();
}
RectangleShape Basket::getShape() {
    return m_Shape;
}
void Basket::moveLeft() { 
    m_MovingLeft = true; 
}
void Basket::moveRight() {
     m_MovingRight = true; 
}
void Basket::stopLeft(){ 
    m_MovingLeft = false; 
}
void Basket::stopRight(){
     m_MovingRight = false; 
}
void Basket::update(Time dt) {
    if (m_MovingLeft && m_Position.x > 0)
        m_Position.x -= m_Speed * dt.asSeconds();
    if (m_MovingRight && m_Position.x + m_Shape.getSize().x < 960)
        m_Position.x += m_Speed * dt.asSeconds();
    m_Shape.setPosition(m_Position);
}
void Basket::reset(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setPosition(m_Position);
    m_MovingLeft = false;
    m_MovingRight = false;
}