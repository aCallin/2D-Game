#ifndef PLAYER_SHOOTING_COMPONENT_HPP
#define PLAYER_SHOOTING_COMPONENT_HPP

#include <SFML\Graphics.hpp>

class PlayerShootingComponent {
private:
    static const int Firerate;

    int _recharge;
    bool _canFire;
public:
    PlayerShootingComponent();

    void handleShooting(const sf::RenderWindow& window, const sf::Vector2f& playerCenter);
};

#endif