#ifndef ENEMY_MANAGER_HPP
#define ENEMY_MANAGER_HPP

#include <SFML\Graphics.hpp>
#include <vector>
#include "Spiderling.hpp"

class EnemyManager {
private:
    std::vector<Spiderling*> _spiderlings;
public:
    EnemyManager();

    void update(const sf::Vector2f& targetPosition);
    void draw(sf::RenderWindow* const window);
};

#endif
