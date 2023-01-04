#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP

#include <SFML\Graphics.hpp>
#include <vector>
#include "Enemy.hpp"

class EnemyManager {
private:
    std::vector<Enemy*> _enemies;
public:
    EnemyManager();

    const std::vector<Enemy*>& getEnemies() const;

    void update(const sf::Vector2f& targetPosition);
    void draw(sf::RenderWindow* const window);
};

#endif
