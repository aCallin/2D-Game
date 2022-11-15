#ifndef SCENE_HPP
#define SCENE_HPP

#include "Engine.hpp"

class Engine;

class Scene {
protected:
    static Engine* _engine;
public:
    Scene();
    virtual ~Scene() = default;
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif