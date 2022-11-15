#ifndef SHEEP_HPP
#define SHEEP_HPP

#include <SFML\Graphics.hpp>
#include <string>
#include <math.h>

class Sheep {
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _facingRight;
public:
    Sheep(const sf::Vector2f& position);
    ~Sheep();

    void update(const sf::Vector2f& avoidLocation, const sf::Vector2f& attractLocation);
    void draw(sf::RenderWindow* const window);

    sf::FloatRect getBounds() const;
    const sf::Vector2f& getCenter() const;
};

#endif