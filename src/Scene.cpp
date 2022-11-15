#include "Scene.hpp"

Engine* Scene::_engine = nullptr;

Scene::Scene() {
    if (Scene::_engine == nullptr)
        Scene::_engine = Engine::getInstance();
}
