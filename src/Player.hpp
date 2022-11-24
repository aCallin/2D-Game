#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

enum FacingDirection { left, right };

class Player {
private:
    int _health;
    sf::Texture _texture;
    sf::Sprite _sprite;
    FacingDirection _facingDirection;
public:
    Player() = default;
    ~Player() = default;

    const int& getHealth() const;
    sf::Texture* const getTexture();
    sf::Sprite* const getSprite();
    const sf::Vector2f& getPosition() const;
    const FacingDirection& getFacingDirection() const;
    
    void setHealth(const int& health);
    void setPosition(const sf::Vector2f& position);
    void setFacingDirection(const FacingDirection& facingDirection);
};

#endif
