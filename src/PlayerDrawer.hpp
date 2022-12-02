#ifndef PLAYER_DRAWER_HPP
#define PLAYER_DRAWER_HPP

#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"
#include "Player.hpp"

class PlayerDrawer {
private:
    Player* _player;
    sf::Image _crosshairImage;
    sf::Cursor _crosshairCursor;
public:
    PlayerDrawer() = default;
    ~PlayerDrawer() = default;

    void setPlayer(Player* const player);

    void load(ResourceManager* const resourceManager, sf::RenderWindow* const window);
    void deload(ResourceManager* const resourceManager, sf::RenderWindow* const window, 
                const sf::Cursor& defaultCursor);
    void draw(sf::RenderWindow* const window);
};

#endif