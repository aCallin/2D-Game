#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    _terrain.load(_engine->getResourceManager());
    _playerDrawer.load(_engine->getResourceManager(), _engine->getWindow());

    _playerController.setPlayer(&_player);
    _playerDrawer.setPlayer(&_player);
}

PlayingScene::~PlayingScene() {
    _terrain.deload(_engine->getResourceManager());
    _playerDrawer.deload(_engine->getResourceManager(), _engine->getWindow(), Engine::DefaultCursor);

    // Reset the camera's center.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(sf::Vector2f(Engine::InternalResolution.x / 2, Engine::InternalResolution.y / 2));
    _engine->getWindow()->setView(view);
}

void PlayingScene::update() {
    // Update the player.
    _playerController.update(*_engine->getWindow());

    // Center the camera on the player.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(_player.getPosition());
    _engine->getWindow()->setView(view);

    // Update the terrain.
    _terrain.update(view.getCenter(), Engine::InternalResolution);

    // Return to the main menu on pressing Escape.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _engine->setScene(new MainMenuScene());
}

void PlayingScene::draw() {
    // Draw the terrain.
    _terrain.draw(_engine->getWindow());

    // Draw the player.
    _playerDrawer.draw(_engine->getWindow());
}
