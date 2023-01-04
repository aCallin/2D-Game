#include "Enemy.hpp"

const float Enemy::ShapeRadius = 30.0f;
const int Enemy::MaxHealth = 3;

Enemy::Enemy(const sf::Vector2f& position) {
    _shape.setPosition(position);
    _shape.setRadius(ShapeRadius);
    _shape.setOrigin(sf::Vector2f(ShapeRadius, ShapeRadius));
    _shape.setFillColor(sf::Color::Red);
    _health = MaxHealth;
}

int Enemy::getHealth() const {
    return _health;
}

void Enemy::setHealth(int health) {
    _health = health;
}

void Enemy::update(const sf::Vector2f& targetPosition) {
    _movementComponent.update(targetPosition, &_shape);
}

void Enemy::draw(sf::RenderWindow* const window) {
    window->draw(_shape);
}
