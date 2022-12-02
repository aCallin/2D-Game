#include "Player.hpp"

const float Player::ShapeRadius = 30.0f;

Player::Player() {
    _shape.setPosition(sf::Vector2f(0, 0));
    _shape.setRadius(ShapeRadius);
    _shape.setOrigin(sf::Vector2f(ShapeRadius, ShapeRadius));
    _shape.setFillColor(sf::Color::Green);
}

const sf::Vector2f& Player::getPosition() const {
    return _shape.getPosition();
}

void Player::update(const sf::RenderWindow& window) {
    _movementComponent.handleMovement(&_shape);
    _shootingComponent.handleShooting(window, _shape.getPosition());
}

void Player::draw(sf::RenderWindow* const window) {
    window->draw(_shape);
}
