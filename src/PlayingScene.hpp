#ifndef INTERACTION_DEMO_SCENE_HPP
#define INTERACTION_DEMO_SCENE_HPP

#include <vector>
#include <limits>
#include "Scene.hpp"
#include "Player.hpp"
#include "PlayerController.hpp"
#include "PlayerDrawer.hpp"

class PlayingScene : public Scene {
private:
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