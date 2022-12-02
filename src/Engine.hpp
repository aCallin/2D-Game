#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML\Graphics.hpp>
#include "Scene.hpp"
#include "ResourceManager.hpp"

class Scene;

class Engine {
private:
    static Engine* _engine;
    sf::RenderWindow _window;
    Scene* _scene;
    ResourceManager _resourceManager;

    Engine();

    void pollEvents();
    void applyAspectRatio();
    void update();
    void draw();
public:
    static Engine* const getInstance();

    static const std::string WindowTitle;
    static const sf::Vector2u InternalResolution;
    static const float TargetAspectRatio;
    static const unsigned int TargetFPS;
    static sf::Cursor DefaultCursor;

    ~Engine();
    Engine(const Engine& other) = delete;
    Engine operator=(const Engine& other) = delete;

    sf::RenderWindow* const getWindow();
    ResourceManager* const getResourceManager();
    void setScene(Scene* scene);

    void doGameLoop();
};

#endif
