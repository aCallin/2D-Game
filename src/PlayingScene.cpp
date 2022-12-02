#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    _previousViewCenter = _engine->getWindow()->getView().getCenter();

    // Load resources.
    _terrain.load(_engine->getResourceManager());
}

PlayingScene::~PlayingScene() {
    // Deload resources.
    _terrain.deload(_engine->getResourceManager());

    // Reset the view's center.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(_previousViewCenter);
    _engine->getWindow()->setView(view);
}

void PlayingScene::update() {
    // Update the player.
    _player.update(*_engine->getWindow());

    // Center the view on the player.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(_player.getPosition());
    _engine->getWindow()->setView(view);

    // Update the terrain.
    _terrain.update(view.getCenter(), Engine::InternalResolution);

    // Return to the main menu on pressing Escape. Keep last.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _engine->setScene(new MainMenuScene());
}

void PlayingScene::draw() {
    // Draw the terrain.
    _terrain.draw(_engine->getWindow());

    // Draw the player.
    _player.draw(_engine->getWindow());
}
