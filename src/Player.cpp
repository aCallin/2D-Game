#include "Player.hpp"

const int& Player::getHealth() const {
    return _health;
}

sf::Texture* const Player::getTexture() {
    return &_texture;
}

sf::Sprite* const Player::getSprite() {
    return &_sprite;
}

const sf::Vector2f& Player::getPosition() const {
    return _sprite.getPosition();
}

const FacingDirection& Player::getFacingDirection() const {
    return _facingDirection;
}

void Player::setHealth(const int& health) {
    _health = health;
}

void Player::setPosition(const sf::Vector2f& position) {
    _sprite.setPosition(position);
}

void Player::setFacingDirection(const FacingDirection& facingDirection) {
    _facingDirection = facingDirection;
}
