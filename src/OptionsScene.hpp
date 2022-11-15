#ifndef OPTIONS_SCENE_HPP
#define OPTIONS_SCENE_HPP

#include "Scene.hpp"

class OptionsScene : public Scene {
private:
public:
    OptionsScene();
    virtual ~OptionsScene() override;
    virtual void update() override;
    virtual void draw() override;
};

#endif