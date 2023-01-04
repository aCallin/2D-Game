#ifndef ENEMY_MOVEMENT_COMPONENT_HPP
#define ENEMY_MOVEMENT_COMPONENT_HPP

#include <SFML\Graphics.hpp>
#include <cmath>

class EnemyMovementComponent {
private:
    const static float MoveSpeed;
public:
    void update(const sf::Vector2f& targetPosition, sf::CircleShape* const enemyShape);
};

#endif