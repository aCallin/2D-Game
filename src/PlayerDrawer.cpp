#include "PlayerDrawer.hpp"

void PlayerDrawer::setPlayer(Player* const player) {
    _player = player;
}

void PlayerDrawer::draw(sf::RenderWindow* const window) {
    window->draw(_player->getCircle());
}
