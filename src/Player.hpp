#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

class Player {
private:
    sf::CircleShape _circle; // Temporary until there is a player texture.
public:
    Player();
    ~Player() = default;

    const sf::CircleShape& getCircle() const;
    const sf::Vector2f& getPosition() const;
    void setPosition(const sf::Vector2f& position);
};

#endif
