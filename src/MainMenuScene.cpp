#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene() {
    _engine->getResourceManager()->addTexture("main_menu_background.png", "main_menu_background");
    _engine->getResourceManager()->addTexture("button_new_game.png", "button_new_game");
    _engine->getResourceManager()->addTexture("button_options.png", "button_options");
    _engine->getResourceManager()->addTexture("button_quit.png", "button_quit");

    // Background sprite.
    const sf::Texture& backgroundTexture = *_engine->getResourceManager()->getTexture("main_menu_background");
    _backgroundSprite.setTexture(backgroundTexture, true);

    // Set button textures.
    const sf::Texture& newGameTexture = *_engine->getResourceManager()->getTexture("button_new_game");
    const sf::Texture& optionsTexture = *_engine->getResourceManager()->getTexture("button_options");
    const sf::Texture& quitTexture = *_engine->getResourceManager()->getTexture("button_quit");
    _newGameButton.setTextures(newGameTexture, newGameTexture, newGameTexture);
    _optionsButton.setTextures(optionsTexture, optionsTexture, optionsTexture);
    _quitButton.setTextures(quitTexture, quitTexture, quitTexture);

    // Position the buttons.
    sf::Vector2f buttonPosition(50, 130);
    const int yIncrement = 150;
    _newGameButton.setPosition(buttonPosition);
    buttonPosition.y += yIncrement;
    _optionsButton.setPosition(buttonPosition);
    buttonPosition.y += yIncrement;
    _quitButton.setPosition(buttonPosition);
}

MainMenuScene::~MainMenuScene() {
    _engine->getResourceManager()->removeTexture("button_new_game");
    _engine->getResourceManager()->removeTexture("button_options");
    _engine->getResourceManager()->removeTexture("button_quit");
}

void MainMenuScene::update() {
    // Update the buttons.
    _newGameButton.update(*_engine->getWindow());
    _optionsButton.update(*_engine->getWindow());
    _quitButton.update(*_engine->getWindow());

    // Do button actions.
    if (_newGameButton.wasClicked())
        _engine->setScene(new PlayingScene());
    if (_optionsButton.wasClicked())
        _engine->setScene(new OptionsScene());
    if (_quitButton.wasClicked())
        _engine->getWindow()->close();
}

void MainMenuScene::draw() {
    // Draw the background.
    _engine->getWindow()->draw(_backgroundSprite);

    // Draw the buttons.
    _newGameButton.draw(_engine->getWindow());
    _optionsButton.draw(_engine->getWindow());
    _quitButton.draw(_engine->getWindow());
}
