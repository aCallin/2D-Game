#include "PlayerMovementComponent.hpp"

const float PlayerMovementComponent::MoveSpeed = 5;

void PlayerMovementComponent::handleMovement(sf::CircleShape* playerShape) {
    // Get the direction the player wants to move.
    sf::Vector2f moveDirection;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        moveDirection.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveDirection.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveDirection.y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveDirection.x += 1;

    // Get the unit vector of that direction.
    sf::Vector2f moveDirectionNormalized;
    if (moveDirection.x != 0 || moveDirection.y != 0) {
        float magnitude = sqrtf(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);
        moveDirectionNormalized = sf::Vector2f(moveDirection.x / magnitude, moveDirection.y / magnitude);
    }

    // Multiply the unit vector by the move speed to get the final move offset.
    sf::Vector2f moveOffset(moveDirectionNormalized.x * MoveSpeed, moveDirectionNormalized.y * MoveSpeed);

    // Apply movement.
    playerShape->move(moveOffset);
}
