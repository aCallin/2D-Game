#include "EnemyManager.hpp"

EnemyManager::EnemyManager() {
    // Test.
    _enemies.push_back(new Enemy(sf::Vector2f(100, 100)));
    _enemies.push_back(new Enemy(sf::Vector2f(200, 100)));
    _enemies.push_back(new Enemy(sf::Vector2f(300, 400)));
}

const std::vector<Enemy*>& EnemyManager::getEnemies() const {
    return _enemies;
}

void EnemyManager::update(const sf::Vector2f& targetPosition) {
    // Delete dead enemies and update each alive one.
    for (int i = _enemies.size() - 1; i >= 0; i--) {
        Enemy* currentEnemy = _enemies[i];
        if (currentEnemy->getHealth() <= 0) {
            _enemies.erase(_enemies.begin() + i);
            delete currentEnemy;
        } else
            _enemies[i]->update(targetPosition);
    }
}

void EnemyManager::draw(sf::RenderWindow* const window) {
    // Draw each enemy.
    for (int i = 0; i < _enemies.size(); i++)
        _enemies[i]->draw(window);
}
