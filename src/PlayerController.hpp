#ifndef PLAYER_CONTROLL_HPP
#define PLAYER_CONTROLL_HPP

#include <SFML\Graphics.hpp>
#include <cmath>
#include "Player.hpp"

class PlayerController {
private:
    Player* _player;
public:
    PlayerController() = default;
    ~PlayerController() = default;

    void setPlayer(Player* const player);

    void update();
};

#endif