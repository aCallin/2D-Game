#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <SFML\Graphics.hpp>
#include <cmath>

class Terrain {
private:
    sf::Texture _tileTexture;
    sf::Vector2u _tileSize;
    sf::Sprite _tileSprite;
    sf::Vector2f _tileOrigin;
    sf::Vector2i _numTiles;
public:
    Terrain();
    ~Terrain() = default;

    void update(const sf::Vector2f& cameraCenter, const sf::Vector2u& internalResolution);
    void draw(sf::RenderWindow* const window);
};

#endif