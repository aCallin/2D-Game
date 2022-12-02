#ifndef PLAYER_MANAGER_HPP
#define PLAYER_MANAGER_HPP

#include <SFML\Graphics.hpp>
#include <cmath>
#include "Player.hpp"

class PlayerManager {
private:
    Player* _player;
public:
    PlayerManager();

    void setPlayer(Player* const player);

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow* const window);
};

#endif
