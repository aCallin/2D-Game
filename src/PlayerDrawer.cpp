#include "PlayerDrawer.hpp"

void PlayerDrawer::setPlayer(Player* const player) {
    _player = player;
    _player->getTexture()->loadFromFile("res/textures/player.png");
    _player->getSprite()->setTexture(*_player->getTexture(), true);
    const sf::Vector2u textureSize = _player->getTexture()->getSize();
    _player->getSprite()->setOrigin(sf::Vector2f(textureSize.x / 2, textureSize.y / 2));
    _player->setFacingDirection(FacingDirection::right);
}

void PlayerDrawer::update() {
    const sf::Vector2f flipVector(-1, 1);
    if (_player->getFacingDirection() == FacingDirection::right && _player->getSprite()->getScale().x < 0)
        _player->getSprite()->scale(flipVector);
    if (_player->getFacingDirection() == FacingDirection::left && _player->getSprite()->getScale().x > 0)
        _player->getSprite()->scale(flipVector);
}

void PlayerDrawer::draw(sf::RenderWindow* const window) {
    window->draw(*_player->getSprite());
}
