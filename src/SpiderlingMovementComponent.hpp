#ifndef SPIDERLING_MOVEMENT_COMPONENT_HPP
#define SPIDERLING_MOVEMENT_COMPONENT_HPP

#include <SFML\Graphics.hpp>
#include <cmath>

class SpiderlingMovementComponent {
private:
    const static float MoveSpeed;
public:
    void update(const sf::Vector2f& targetPosition, sf::CircleShape* const spiderlingShape);
};

#endif