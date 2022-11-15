#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include <string>
#include "Scene.hpp"
#include "Button.hpp"
#include "PlayingScene.hpp"
#include "OptionsScene.hpp"

class MainMenuScene : public Scene {
private:
    Button newGameButton;
    Button optionsButton;
    Button quitButton;
public:
    MainMenuScene();
    virtual ~MainMenuScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif