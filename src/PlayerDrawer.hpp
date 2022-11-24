#ifndef PLAYER_DRAWER_HPP
#define PLAYER_DRAWER_HPP

#include <SFML\Graphics.hpp>
#include "Player.hpp"

class PlayerDrawer {
private:
    Player* _player;
public:
    PlayerDrawer() = default;
    ~PlayerDrawer() = default;

    void setPlayer(Player* const player);

    void update();
    void draw(sf::RenderWindow* const window);
};

#endif