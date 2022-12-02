#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include <SFML\Graphics.hpp>
#include <string>
#include "Scene.hpp"
#include "Button.hpp"
#include "PlayingScene.hpp"
#include "OptionsScene.hpp"

class MainMenuScene : public Scene {
private:
    Button _newGameButton;
    Button _optionsButton;
    Button _quitButton;
    sf::Sprite _backgroundSprite;
public:
    MainMenuScene();
    virtual ~MainMenuScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif