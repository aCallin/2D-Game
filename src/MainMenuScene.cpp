#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene() {
    _engine->getResourceManager()->addTexture("button_new_game.png", "button_new_game");
    _engine->getResourceManager()->addTexture("button_options.png", "button_options");
    _engine->getResourceManager()->addTexture("button_quit.png", "button_quit");

    const sf::Texture& newGameTexture = *_engine->getResourceManager()->getTexture("button_new_game");
    const sf::Texture& optionsTexture = *_engine->getResourceManager()->getTexture("button_options");
    const sf::Texture& quitTexture = *_engine->getResourceManager()->getTexture("button_quit");
    newGameButton.setTextures(newGameTexture, newGameTexture, newGameTexture);
    optionsButton.setTextures(optionsTexture, optionsTexture, optionsTexture);
    quitButton.setTextures(quitTexture, quitTexture, quitTexture);

    // Position the buttons.
    sf::Vector2f buttonPosition(50, 130);
    const int yIncrement = 150;
    newGameButton.setPosition(buttonPosition);
    buttonPosition.y += yIncrement;
    optionsButton.setPosition(buttonPosition);
    buttonPosition.y += yIncrement;
    quitButton.setPosition(buttonPosition);
}

MainMenuScene::~MainMenuScene() {
    _engine->getResourceManager()->removeTexture("button_new_game");
    _engine->getResourceManager()->removeTexture("button_options");
    _engine->getResourceManager()->removeTexture("button_quit");
}

void MainMenuScene::update() {
    // Update the buttons.
    newGameButton.update(*_engine->getWindow());
    optionsButton.update(*_engine->getWindow());
    quitButton.update(*_engine->getWindow());

    // Do button actions.
    if (newGameButton.wasClicked())
        _engine->setScene(new PlayingScene());
    if (optionsButton.wasClicked())
        _engine->setScene(new OptionsScene());
    if (quitButton.wasClicked())
        _engine->getWindow()->close();
}

void MainMenuScene::draw() {
    // Draw the buttons.
    newGameButton.draw(_engine->getWindow());
    optionsButton.draw(_engine->getWindow());
    quitButton.draw(_engine->getWindow());
}
