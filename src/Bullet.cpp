#include "Bullet.hpp"

Bullet::Bullet(const sf::Vector2f& position, const sf::Vector2f& direction, float speed, float radius, 
               const sf::Color& color, Source source) {
    _shape.setOrigin(sf::Vector2f(radius, radius));
    _shape.setPosition(position);
    _direction = direction;
    _speed = speed;
    _shape.setRadius(radius);
    _shape.setFillColor(color);
    _source = source;
    _age = 0;
}

const sf::CircleShape& Bullet::getShape() const {
    return _shape;
}

const sf::Vector2f& Bullet::getDirection() const {
    return _direction;
}

float Bullet::getSpeed() const {
    return _speed;
}

Source Bullet::getSource() const {
    return _source;
}

int Bullet::getAge() const {
    return _age;
}

void Bullet::setAge(int age) {
    _age = age;
}

void Bullet::move(const sf::Vector2f& offset) {
    _shape.move(offset);
}
