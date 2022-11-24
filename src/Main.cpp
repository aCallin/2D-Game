#include <iostream>
#include "Engine.hpp"
#include "MainMenuScene.hpp"

int main(int argc, char *argv[]) {
    std::cout << "Hello, world!" << std::endl;

    Engine* const engine = Engine::getInstance();
    engine->setScene(new MainMenuScene());
    engine->doGameLoop();
    delete engine;
    
    std::cout << "Goodbye!" << std::endl;
    return EXIT_SUCCESS;
}