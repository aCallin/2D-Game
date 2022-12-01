#ifndef PLAYING_SCENE_HPP
#define PLAYING_SCENE_HPP

#include "Scene.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "PlayerController.hpp"
#include "PlayerDrawer.hpp"

class PlayingScene : public Scene {
private:
    Terrain _terrain;
    Player _player;
    PlayerController _playerController;
    PlayerDrawer _playerDrawer;
public:
    PlayingScene();
    virtual ~PlayingScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif