#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>
#include "PlayerMovementComponent.hpp"
#include "PlayerShootingComponent.hpp"
#include "BulletManager.hpp"

class Player {
private:
    static const float ShapeRadius;

    sf::CircleShape _shape;
    PlayerMovementComponent _movementComponent;
    PlayerShootingComponent _shootingComponent;
public:
    Player();

    const sf::Vector2f& getPosition() const;
    
    void update(const sf::RenderWindow& window, BulletManager* const bulletManager);
    void draw(sf::RenderWindow* const window);
};

#endif
