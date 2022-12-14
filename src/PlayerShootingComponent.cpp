#include "PlayerShootingComponent.hpp"

const float PlayerShootingComponent::ShotSpeed = 30;
const float PlayerShootingComponent::ShotRadius = 10;
const sf::Color PlayerShootingComponent::ShotColor = sf::Color::Green;
const int PlayerShootingComponent::ShotDelay = 30;

PlayerShootingComponent::PlayerShootingComponent() {
    _recharge = 0;
    _canFire = true;
}

void PlayerShootingComponent::handleShooting(const sf::RenderWindow& window, const sf::Vector2f& playerCenter, 
                                             BulletManager* const bulletManager) {
    // Recharge shot if the player can't shoot yet.
    if (!_canFire) {
        _recharge++;
        if( _recharge >= ShotDelay) {
            _canFire = true;
            _recharge = 0;
        }
    }

    // Shoot.
    if (_canFire && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Calculate aim direction unit vector.
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2f aimDirection = mousePosition - playerCenter;
        if (aimDirection.x != 0 || aimDirection.y != 0) {
            float aimDistance = sqrtf((aimDirection.x * aimDirection.x) + (aimDirection.y * aimDirection.y));
            aimDirection.x = aimDirection.x / aimDistance;
            aimDirection.y = aimDirection.y / aimDistance;
        }

        // Fire a bullet.
        bulletManager->addBullet(new Bullet(playerCenter, aimDirection, ShotSpeed, ShotRadius, ShotColor, player));
        _canFire = false;
    }
}
