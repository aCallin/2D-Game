#include "PlayerShootingComponent.hpp"

const int PlayerShootingComponent::Firerate = 5;

PlayerShootingComponent::PlayerShootingComponent() {
    _recharge = 0;
    _canFire = true;
}

void PlayerShootingComponent::handleShooting(const sf::RenderWindow& window, const sf::Vector2f& playerCenter) {
    // Recharge shot and check if the player can shoot.
    if (!_canFire) {
        _recharge++;
        if( _recharge == Firerate) {
            _canFire = true;
            _recharge = 0;
        }
    }

    // Shoot.
    if (_canFire && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f aimLocation = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // TODO: Actually fire a bullet.

        _canFire = false;
    }
}
