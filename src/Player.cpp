#include "Player.hpp"

Player::Player() {
    const float radius = 50.0f;
    _circle.setPosition(sf::Vector2f(0, 0));
    _circle.setRadius(radius);
    _circle.setOrigin(sf::Vector2f(radius, radius));
    _circle.setFillColor(sf::Color::Green);
}

const sf::CircleShape& Player::getCircle() const {
    return _circle;
}

const sf::Vector2f& Player::getPosition() const {
    return _circle.getPosition();
}

void Player::setPosition(const sf::Vector2f& position) {
    _circle.setPosition(position);
}
