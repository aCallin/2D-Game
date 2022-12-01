#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    _playerController.setPlayer(&_player);
    _playerDrawer.setPlayer(&_player);
}

PlayingScene::~PlayingScene() {

}

void PlayingScene::update() {
    // Update the player.
    _playerController.update();

    // Center the camera on the player.
    sf::View view = _engine->getWindow()->getView();
    view.setCenter(_player.getPosition());
    _engine->getWindow()->setView(view);

    // Update the terrain.
    _terrain.update(view.getCenter(), Engine::InternalResolution);
}

void PlayingScene::draw() {
    // Draw the terrain.
    _terrain.draw(_engine->getWindow());

    // Draw the player.
    _playerDrawer.draw(_engine->getWindow());
}
