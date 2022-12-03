#ifndef BULLET_MANAGER_HPP
#define BULLET_MANAGER_HPP

#include <SFML\Graphics.hpp>
#include <vector>
#include "Bullet.hpp"

class BulletManager {
private:
    const static int BulletLifespan;

    std::vector<Bullet*> _bullets;
public:
    ~BulletManager();

    void addBullet(Bullet* const bullet);

    void update();
    void draw(sf::RenderWindow* const window) const;
};

#endif
