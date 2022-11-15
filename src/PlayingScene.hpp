#ifndef INTERACTION_DEMO_SCENE_HPP
#define INTERACTION_DEMO_SCENE_HPP

#include <vector>
#include <limits>
#include "Scene.hpp"
#include "Player.hpp"
#include "Sheep.hpp"

class PlayingScene : public Scene {
private:
    Player player;
    std::vector<Sheep*> sheep;
public:
    PlayingScene();
    virtual ~PlayingScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif