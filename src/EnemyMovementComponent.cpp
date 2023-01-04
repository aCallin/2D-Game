#include "EnemyMovementComponent.hpp"

const float EnemyMovementComponent::MoveSpeed = 3.0f;

void EnemyMovementComponent::update(const sf::Vector2f& targetPosition, sf::CircleShape* const enemyShape) {
    // Calculate the move direction unit vector.
    sf::Vector2f moveDirection = targetPosition - enemyShape->getPosition();
    if (moveDirection.x != 0 || moveDirection.y != 0) {
        float magnitude = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y));
        moveDirection.x /= magnitude;
        moveDirection.y /= magnitude;
    }

    // Multiply move direction by movement speed to get the move offset vector.
    const sf::Vector2f moveOffset(moveDirection.x * MoveSpeed, moveDirection.y * MoveSpeed);

    // Apply movement.
    enemyShape->move(moveOffset);
}
