#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

class Player {
private:
    sf::CircleShape _circle; // Temporary until there is a player texture.
    sf::Vector2f _aimLocation;
public:
    Player();
    ~Player() = default;

    const sf::CircleShape& getCircle() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getAimLocation() const;
    void setPosition(const sf::Vector2f& position);
    void setAimLocation(const sf::Vector2f& aimLocation);
};

#endif
