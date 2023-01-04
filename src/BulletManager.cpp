#include "BulletManager.hpp"

const int BulletManager::BulletLifespan = 300;

bool BulletManager::collides(const sf::CircleShape& bulletShape, const sf::CircleShape& targetShape) const {
    const float distanceToCollision = bulletShape.getRadius() + targetShape.getRadius();
    const sf::Vector2f bulletCenter(bulletShape.getGlobalBounds().left + bulletShape.getGlobalBounds().width / 2, 
                                    bulletShape.getGlobalBounds().top + bulletShape.getGlobalBounds().height / 2);
    const sf::Vector2f targetCenter(targetShape.getGlobalBounds().left + targetShape.getGlobalBounds().width / 2, 
                                    targetShape.getGlobalBounds().top + targetShape.getGlobalBounds().height / 2);
    
    const sf::Vector2f distanceVector = targetCenter - bulletCenter;
    float distance = 0;
    if (distanceVector.x != 0 || distanceVector.y != 0)
        distance = sqrtf(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

    return distance <= distanceToCollision;
}

BulletManager::~BulletManager() {
    for (int i = 0; i < _bullets.size(); i++)
        delete _bullets[i];
    _bullets.clear();
}

void BulletManager::addBullet(Bullet* const bullet) {
    _bullets.push_back(bullet);
}

#include <iostream> // TODO: remove me.
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

            // Hit enemies.
            for (int j = 0; j < enemies.size(); j++) {
                if (collides(bullet->getShape(), enemies[j]->getShape())) {
                    enemies[j]->setHealth(enemies[j]->getHealth() - 1);
                    _bullets.erase(_bullets.begin() + i);
                    delete bullet;
                    break; // Don't check for more collisions after the bullet has been deleted.
                }
            }
        }
    }
}

void BulletManager::draw(sf::RenderWindow* const window) const {
    for (Bullet* bullet : _bullets)
        window->draw(bullet->getShape());
}
