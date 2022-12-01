#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <SFML\Graphics.hpp>
#include <cmath>
#include "ResourceManager.hpp"

class Terrain {
private:
    sf::Texture* _tileTexture;
    sf::Vector2u _tileSize;
    sf::Sprite _tileSprite;
    sf::Vector2f _tileOrigin;
    sf::Vector2i _numTiles;
public:
    Terrain() = default;
    ~Terrain() = default;

    void load(ResourceManager* const resourceManager);
    void deload(ResourceManager* const resourceManager);
    void update(const sf::Vector2f& cameraCenter, const sf::Vector2u& internalResolution);
    void draw(sf::RenderWindow* const window);
};

#endif