#include "PlayingScene.hpp"

PlayingScene::PlayingScene() {
    sheep.push_back(new Sheep(sf::Vector2f(300, 100)));
    sheep.push_back(new Sheep(sf::Vector2f(400, 200)));
    sheep.push_back(new Sheep(sf::Vector2f(350, 150)));
}

PlayingScene::~PlayingScene() {

}

void PlayingScene::update() {
    ///// UPDATE LOOP LOGIC /////

    // PSEUDO CODE
    // input: keyboard presses -> update player -> output: proposed position
    // input: player's proposed position -> collision system -> output: player's actual position
    // for each sheep:
    //     input: avoid location: player position, attract location: nearest other sheep -> update sheep -> output: proposed position
    //     input: sheep's proposed position -> collision system -> output: sheep's actual position

    // NOTES
    // - to get the general structure implemented, for now the collision system can just carry the input through to the 
    //   output

    /////////////////////////////

    player.update();

    // Sheep behaviour.
    sf::Vector2f avoidLocation = player.getCenter();
    for (int i = 0; i < sheep.size(); i++) {
        // Find the closest other sheep to this sheep.
        const float floatMax = std::numeric_limits<float>::max();
        sf::Vector2f attractLocation(floatMax, floatMax);
        float attractMagnitude = floatMax;
        
        for (int j = 0; j < sheep.size(); j++) {
            if (j == i) // Don't compare a sheep to itself.
                continue;

            sf::Vector2f newAttractLocation = sheep[j]->getCenter();
            float newAttractMagnitude = 0;
            if (newAttractLocation.x != 0 || newAttractLocation.y != 0) {
                sf::Vector2f distance = newAttractLocation - sheep[i]->getCenter();
                newAttractMagnitude = sqrtf((distance.x * distance.x) + (distance.y * distance.y));
            }
            if (newAttractMagnitude < attractMagnitude) {
                attractLocation = newAttractLocation;
                attractMagnitude = newAttractMagnitude;
            }
        }
        
        // Finally, update the sheep with the known avoid location and attract location.
        sheep[i]->update(avoidLocation, attractLocation);
    }
}

void PlayingScene::draw() {
    for (int i = 0; i < sheep.size(); i++)
        sheep[i]->draw(_engine->getWindow());
    player.draw(_engine->getWindow());
}
