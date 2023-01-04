#include "BulletManager.hpp"

const int BulletManager::BulletLifespan = 300;

BulletManager::~BulletManager() {
    for (int i = 0; i < _bullets.size(); i++)
        delete _bullets[i];
    _bullets.clear();
}

void BulletManager::addBullet(Bullet* const bullet) {
    _bullets.push_back(bullet);
}

void BulletManager::update(const std::vector<Enemy*>& enemies) {
    for (int i = _bullets.size() - 1; i >= 0; i--) {
        Bullet* const bullet = _bullets[i];

        // Increase age of the bullet. Delete bullet if it has exceeded its lifespan.
        bullet->setAge(bullet->getAge() + 1);
        if (bullet->getAge() >= BulletLifespan) {
            _bullets.erase(_bullets.begin() + i);
            delete bullet;
        } else {
            // Move the bullet in its current direction.
            sf::Vector2f moveOffset = bullet->getDirection();
            moveOffset.x *= bullet->getSpeed();
            moveOffset.y *= bullet->getSpeed();
            bullet->move(moveOffset);
        }
    }
}

void BulletManager::draw(sf::RenderWindow* const window) const {
    for (Bullet* bullet : _bullets)
        window->draw(bullet->getShape());
}
