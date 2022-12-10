#ifndef SPIDERLING_HPP
#define SPIDERLING_HPP

#include <SFML\Graphics.hpp>
#include "SpiderlingMovementComponent.hpp"

class Spiderling {
private:
    static const float ShapeRadius;

    sf::CircleShape _shape;
    SpiderlingMovementComponent _movementComponent;

public:
    Spiderling(const sf::Vector2f& position);

    void update(const sf::Vector2f& targetPosition);
    void draw(sf::RenderWindow* const window);
};

#endif
