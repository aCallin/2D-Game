#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene() {
    // Load in the button textures.
    const std::string newGameTexturePath = "res/textures/new-game.png";
    const std::string optionsTexturePath = "res/textures/options.png";
    const std::string quitTexturePath = "res/textures/quit.png";
    newGameButton.setTexturePaths(newGameTexturePath, newGameTexturePath, newGameTexturePath);
    optionsButton.setTexturePaths(optionsTexturePath, optionsTexturePath, optionsTexturePath);
    quitButton.setTexturePaths(quitTexturePath, quitTexturePath, quitTexturePath);

    // Scale the buttons.
    const sf::Vector2f scaleFactors(0.5, 0.5);
    newGameButton.setScale(scaleFactors);
    optionsButton.setScale(scaleFactors);
    quitButton.setScale(scaleFactors);

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
        _engine->getWindow()->close(); // Trying to mimic sf::Event::Closed.
}

void MainMenuScene::draw() {
    // Draw the buttons.
    newGameButton.draw(_engine->getWindow());
    optionsButton.draw(_engine->getWindow());
    quitButton.draw(_engine->getWindow());
}
