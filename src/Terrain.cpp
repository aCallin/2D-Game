#include "Terrain.hpp"

void Terrain::load(ResourceManager* const resourceManager) {
    resourceManager->addTexture("terrain_tile.png", "terrain_tile");
    _tileTexture = resourceManager->getTexture("terrain_tile");
    _tileSize = _tileTexture->getSize();
    _tileSprite.setTexture(*_tileTexture, true);
}

void Terrain::deload(ResourceManager* const resourceManager) {
    resourceManager->removeTexture("terrain_tile");
}

void Terrain::update(const sf::Vector2f& cameraCenter, const sf::Vector2u& internalResolution) {
    const int cameraLeft = cameraCenter.x - (internalResolution.x / 2);
    const int cameraRight = cameraCenter.x + (internalResolution.x / 2);
    const int cameraTop = cameraCenter.y - (internalResolution.y / 2);
    const int cameraBottom = cameraCenter.y + (internalResolution.y / 2);

    // Calculate where the first tile / the top-left tile needs to be drawn.
    _tileOrigin.x = floor(cameraCenter.x / _tileSize.x) * _tileSize.x;
    _tileOrigin.y = floor(cameraCenter.y / _tileSize.y) * _tileSize.y;
    while (_tileOrigin.x > cameraLeft)
        _tileOrigin.x -= _tileSize.x;
    while (_tileOrigin.y > cameraTop)
        _tileOrigin.y -= _tileSize.y;

    // Calculate how many tiles need to be drawn to cover the screen.
    _numTiles = sf::Vector2i(0, 0);
    int scanX = _tileOrigin.x;
    int scanY = _tileOrigin.y;
    while (scanX < cameraRight) {
        scanX += _tileSize.x;
        _numTiles.x++;
    }
    while (scanY < cameraBottom) {
        scanY += _tileSize.y;
        _numTiles.y++;
    }
}

void Terrain::draw(sf::RenderWindow* const window) {
    // Draw the tiles.
    for (int column = 0; column < _numTiles.x; column++) {
        for (int row = 0; row < _numTiles.y; row++) {
            sf::Vector2f drawPosition(_tileOrigin.x + (_tileSize.x * column), _tileOrigin.y + (_tileSize.y * row));
            _tileSprite.setPosition(drawPosition);
            window->draw(_tileSprite);
        }
    }
}
