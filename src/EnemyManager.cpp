#include "EnemyManager.hpp"

EnemyManager::EnemyManager() {
    _spiderlings.push_back(new Spiderling(sf::Vector2f(100, 100)));
    _spiderlings.push_back(new Spiderling(sf::Vector2f(200, 100)));
    _spiderlings.push_back(new Spiderling(sf::Vector2f(300, 400)));
}

void EnemyManager::update(const sf::Vector2f& targetPosition) {
    for (int i = _spiderlings.size() - 1; i >= 0; i--) {
        Spiderling* currentSpiderling = _spiderlings[i];
        if (currentSpiderling->getHealth() <= 0) {
            _spiderlings.erase(_spiderlings.begin() + i);
            delete currentSpiderling;
        } else
            _spiderlings[i]->update(targetPosition);
    }
}

void EnemyManager::draw(sf::RenderWindow* const window) {
    for (int i = 0; i < _spiderlings.size(); i++)
        _spiderlings[i]->draw(window);
}
