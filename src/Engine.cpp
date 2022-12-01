#include "Engine.hpp"

Engine* Engine::_engine = nullptr;

const std::string Engine::WindowTitle = "Unnamed Project";
const sf::Vector2u Engine::InternalResolution = sf::Vector2u(1280, 720);
const float Engine::TargetAspectRatio = (float)Engine::InternalResolution.x / Engine::InternalResolution.y;
const unsigned int Engine::TargetFPS = 60;

Engine* const Engine::getInstance() {
    if (Engine::_engine == nullptr)
        Engine::_engine = new Engine();
    return Engine::_engine;
}

Engine::Engine() {
    _window.create(sf::VideoMode(InternalResolution.x, InternalResolution.y), WindowTitle);
    _window.setFramerateLimit(TargetFPS);
    _scene = nullptr;
}

Engine::~Engine() {
    if (_scene != nullptr)
        delete _scene;
}

sf::RenderWindow* const Engine::getWindow() {
    return &_window;
}

void Engine::setScene(Scene* _scene) {
    if (this->_scene != nullptr) // Scene will be null at least the first time this method is called.
        delete this->_scene;
    this->_scene = _scene;
}

void Engine::doGameLoop() {
    while (_window.isOpen()) {
        pollEvents();
        if (_window.isOpen()) { // Check again in case the window just now closed from pollEvents().
            update();
            draw();
        }
    }
}

void Engine::pollEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::Resized)
            applyAspectRatio();
    }
}

void Engine::applyAspectRatio() {
    sf::Vector2u windowSize = _window.getSize();

	// Determine viewport size and position in pixels.
    sf::Vector2u viewportSizePixels = sf::Vector2u(windowSize.x, windowSize.x / TargetAspectRatio);
    if (viewportSizePixels.y > windowSize.y) {
        viewportSizePixels.x = windowSize.y * TargetAspectRatio;
        viewportSizePixels.y = windowSize.y;
    }
    sf::Vector2u viewportPositionPixels = (windowSize - viewportSizePixels) / 2u;

    // Determine viewport size and position as fractions relative to the window.
    sf::Vector2f viewportSizeFraction = 
        sf::Vector2f((float)viewportSizePixels.x / windowSize.x, (float)viewportSizePixels.y / windowSize.y);
    sf::Vector2f viewportPositionFraction = 
        sf::Vector2f((float)viewportPositionPixels.x / windowSize.x, (float)viewportPositionPixels.y / windowSize.y);

    // Apply changes.
    sf::FloatRect viewport = sf::FloatRect(viewportPositionFraction, viewportSizeFraction);
    sf::View view = _window.getView();
    view.setViewport(viewport);
    _window.setView(view);
}

void Engine::update() {
    if (_scene != nullptr)
        _scene->update();
}

void Engine::draw() {
    _window.clear(sf::Color::Black);
    if (_scene != nullptr)
        _scene->draw();
    _window.display();
}
