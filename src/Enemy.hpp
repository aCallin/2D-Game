#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML\Graphics.hpp>
#include "EnemyMovementComponent.hpp"

class Enemy {
private:
    static const float ShapeRadius;
    static const int MaxHealth;

    sf::CircleShape _shape;
    int _health;
    EnemyMovementComponent _movementComponent;

public:
    Enemy(const sf::Vector2f& position);

    const sf::CircleShape& getShape() const;
    int getHealth() const;

    void setHealth(int health);

    void update(const sf::Vector2f& targetPosition);
    void draw(sf::RenderWindow* const window);
};

#endif
