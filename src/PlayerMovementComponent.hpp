#ifndef PLAYER_MOVEMENT_COMPONENT_HPP
#define PLAYER_MOVEMENT_COMPONENT_HPP

#include <SFML\Graphics.hpp>
#include <cmath>

class PlayerMovementComponent {
private:
    static const float MoveSpeed;
public:
    void handleMovement(sf::CircleShape* playerShape);
};

#endif
