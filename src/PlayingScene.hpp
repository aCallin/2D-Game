#ifndef PLAYING_SCENE_HPP
#define PLAYING_SCENE_HPP

#include "Scene.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "PlayerManager.hpp"
#include "MainMenuScene.hpp"

class PlayingScene : public Scene {
private:
    Terrain _terrain;
    Player _player;
    PlayerManager _playerManager;
public:
    PlayingScene();
    virtual ~PlayingScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif
