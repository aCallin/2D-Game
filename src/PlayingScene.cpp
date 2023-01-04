#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    // Store the current state of the view before we center it on the player.
    _previousViewState = _engine->getWindow()->getView();

    // Load resources.
    _terrain.load(_engine->getResourceManager());
}

PlayingScene::~PlayingScene() {
    // Deload resources.
    _terrain.deload(_engine->getResourceManager());

    // Reset the view.
    _engine->getWindow()->setView(_previousViewState);
}

void PlayingScene::update() {
    // Update the player.
    _player.update(*_engine->getWindow(), &_bulletManager);

    // Center the view on the player.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(_player.getPosition());
    _engine->getWindow()->setView(view);

    // Update the terrain.
    _terrain.update(view.getCenter(), Engine::InternalResolution);

    // Update enemies.
    _enemyManager.update(_player.getPosition());

    // Update bullet manager.
    _bulletManager.update(_enemyManager.getEnemies());

    // Return to the main menu on pressing Escape. Keep last.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        _engine->setScene(new MainMenuScene());
}

void PlayingScene::draw() {
    // Draw the terrain.
    _terrain.draw(_engine->getWindow());

    // Draw bullets.
    _bulletManager.draw(_engine->getWindow());

    // Draw the player.
    _player.draw(_engine->getWindow());

    // Draw enemies.
    _enemyManager.draw(_engine->getWindow());
}
