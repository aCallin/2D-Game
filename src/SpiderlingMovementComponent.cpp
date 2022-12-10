#include "SpiderlingMovementComponent.hpp"

const float SpiderlingMovementComponent::MoveSpeed = 3.0f;

void SpiderlingMovementComponent::update(const sf::Vector2f& targetPosition, sf::CircleShape* const spiderlingShape) {
    // Calculate the move direction unit vector.
    sf::Vector2f moveDirection = targetPosition - spiderlingShape->getPosition();
    if (moveDirection.x != 0 || moveDirection.y != 0) {
        float magnitude = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y));
        moveDirection.x /= magnitude;
        moveDirection.y /= magnitude;
    }

    // Multiply move direction by movement speed to get the move offset vector.
    const sf::Vector2f moveOffset(moveDirection.x * MoveSpeed, moveDirection.y * MoveSpeed);

    // Apply movement.
    spiderlingShape->move(moveOffset);
}
