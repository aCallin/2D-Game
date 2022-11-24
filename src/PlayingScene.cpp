#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    _playerController.setPlayer(&_player);
    _playerDrawer.setPlayer(&_player);
}

PlayingScene::~PlayingScene() {

}

void PlayingScene::update() {
    _playerController.update();
    _playerDrawer.update();
}

void PlayingScene::draw() {
    _playerDrawer.draw(_engine->getWindow());
}
