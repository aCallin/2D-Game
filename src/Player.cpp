#include "Player.hpp"

Player::Player() {
    const std::string texturePath = "res/textures/sheepdog.png";
    const float spriteScale = 0.7f;

    _texture.loadFromFile(texturePath);
    const sf::Vector2u size = _texture.getSize();
    _sprite.setTexture(_texture, true);
    _sprite.setScale(sf::Vector2f(spriteScale, spriteScale));
    _sprite.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

    sf::Vector2f centerScreen(Engine::InternalResolution.x / 2, Engine::InternalResolution.y / 2);
    _sprite.setPosition(centerScreen);
    _facingRight = true;
}

Player::~Player() {

}

void Player::update() {
    const float walkSpeed = 6;
    const float runSpeed = 10;

    // Determine move direction unit vector.
    sf::Vector2f moveDirection;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        moveDirection.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveDirection.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveDirection.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveDirection.x += 1;
    if (moveDirection.x != 0 && moveDirection.y != 0) {
        float moveDirectionMagnitude = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y));
        moveDirection.x /= moveDirectionMagnitude;
        moveDirection.y /= moveDirectionMagnitude;
    }

    // Determine facing direction. Flip the sprite if there was a change in facing direction.
    const sf::Vector2f flipVector(-1, 1);
    if (moveDirection.x > 0) {
        if (!_facingRight)
            _sprite.scale(flipVector);
        _facingRight = true;
    }
    if (moveDirection.x < 0) {
        if (_facingRight)
            _sprite.scale(flipVector);
        _facingRight = false;
    }

    // Apply movement. Move speed depends on if the player is walking or running.
    float moveSpeed = walkSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        moveSpeed = runSpeed;
    sf::Vector2f moveOffset(moveDirection.x * moveSpeed, moveDirection.y * moveSpeed);
    _sprite.setPosition(_sprite.getPosition() + moveOffset);
}

void Player::draw(sf::RenderWindow* const window) {
    window->draw(_sprite);
}

const sf::Vector2f& Player::getCenter() const {
    return _sprite.getPosition();
}
