#ifndef PLAYER_SHOOTING_COMPONENT_HPP
#define PLAYER_SHOOTING_COMPONENT_HPP

#include <SFML\Graphics.hpp>
#include <cmath>
#include "BulletManager.hpp"

class PlayerShootingComponent {
private:
    const static float ShotSpeed;
    const static float ShotRadius;
    const static sf::Color ShotColor;
    const static int ShotDelay;

    int _recharge;
    bool _canFire;
public:
    PlayerShootingComponent();

    void handleShooting(const sf::RenderWindow& window, const sf::Vector2f& playerCenter, 
                        BulletManager* const bulletManager);
};

#endif