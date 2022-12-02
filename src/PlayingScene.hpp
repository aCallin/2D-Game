#ifndef PLAYING_SCENE_HPP
#define PLAYING_SCENE_HPP

#include "Scene.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "MainMenuScene.hpp"

class PlayingScene : public Scene {
private:
    sf::Vector2f _previousViewCenter;
    Terrain _terrain;
    Player _player;
public:
    PlayingScene();
    virtual ~PlayingScene() override;

    virtual void update() override;
    virtual void draw() override;
};

#endif
