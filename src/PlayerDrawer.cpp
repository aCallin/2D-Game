#include "PlayerDrawer.hpp"

void PlayerDrawer::setPlayer(Player* const player) {
    _player = player;
}

void PlayerDrawer::load(ResourceManager* const resourceManager, sf::RenderWindow* const window) {
    resourceManager->addTexture("player_crosshair.png", "player_crosshair");
    
    // Change cursor to a crosshair.
    const sf::Texture& crosshairTexture = *resourceManager->getTexture("player_crosshair");
    _crosshairImage = crosshairTexture.copyToImage();
    sf::Vector2u crosshairSize = crosshairTexture.getSize();
    sf::Vector2u crosshairHotspot(crosshairSize.x / 2, crosshairSize.y / 2);
    _crosshairCursor.loadFromPixels(_crosshairImage.getPixelsPtr(), crosshairSize, crosshairHotspot);
    window->setMouseCursor(_crosshairCursor);
}

void PlayerDrawer::deload(ResourceManager* const resourceManager, sf::RenderWindow* const window, 
                          const sf::Cursor& defaultCursor) {
    resourceManager->removeTexture("player_crosshair");
    window->setMouseCursor(defaultCursor);
}

void PlayerDrawer::draw(sf::RenderWindow* const window) {
    window->draw(_player->getCircle());
}
