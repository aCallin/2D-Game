#ifndef PLAYING_SCENE_HPP
#define PLAYING_SCENE_HPP

#include <SFML\Graphics.hpp>
#include "Scene.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "BulletManager.hpp"
#include "EnemyManager.hpp"
#include "MainMenuScene.hpp"

class PlayingScene : public Scene {
private:
    sf::View _previousViewState;
    Terrain _terrain;
    Player _player;
    BulletManager _bulletManager;
    EnemyManager _enemyManager;
public:
    PlayingScene();
    virtual ~PlayingScene() override;

    virtual void update() override;
    virtual void draw() override;
};

#endif
