#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>
#include <string.h>
#include <math.h>
#include "Engine.hpp"

class Player {
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _facingRight;

public:
    Player();
    ~Player();

    void update();
    void draw(sf::RenderWindow* const window);

    const sf::Vector2f& getCenter() const;
};

#endif