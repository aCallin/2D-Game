#include "Sheep.hpp"

Sheep::Sheep(const sf::Vector2f& position) {
    const std::string texturePath = "res/textures/sheep.png";
    _texture.loadFromFile(texturePath);
    const sf::Vector2u size = _texture.getSize();
    _sprite.setTexture(_texture, true);
    _sprite.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
    _sprite.setPosition(position);
}

Sheep::~Sheep() {

}

void Sheep::update(const sf::Vector2f& avoidLocation, const sf::Vector2f& attractLocation) {
    // Calculate repel direction unit vector.
    sf::Vector2f repelDirection = _sprite.getPosition() - avoidLocation;
    float repelMagnitude = 0;
    if (repelDirection.x != 0 && repelDirection.y != 0) {
        repelMagnitude = sqrtf((repelDirection.x * repelDirection.x) + (repelDirection.y * repelDirection.y));
        repelDirection.x /= repelMagnitude;
        repelDirection.y /= repelMagnitude;
    }

    // Calculate the repel offset.
    float repelMultiplier = 1000 / repelMagnitude;
    if (repelMultiplier <= 3)
        repelMultiplier = 0;
    const sf::Vector2f repelOffset(repelDirection.x * repelMultiplier, repelDirection.y * repelMultiplier);

    // Calculate attract location unit vector.
    sf::Vector2f attractDirection = attractLocation - _sprite.getPosition();
    float attractMagnitude = 0;
    if (attractDirection.x != 0 && attractDirection.y != 0) {
        attractMagnitude = sqrtf((attractDirection.x * attractDirection.x) + (attractDirection.y * attractDirection.y));
        attractDirection.x /= attractMagnitude;
        attractDirection.y /= attractMagnitude;
    }

    // Calculate the attract offset.
    float attractMultiplier = attractMagnitude / 100;
    if (attractMultiplier <= 1 || attractMultiplier >= 7)
        attractMultiplier = 0;
    if (attractMultiplier >= 3 && attractMultiplier < 7)
        attractMultiplier = 3;
    const sf::Vector2f attractOffset(attractDirection.x * attractMultiplier, attractDirection.y * attractMultiplier);

    // Sum the repel and attract offsets to get the final move offset.
    sf::Vector2f moveOffset = repelOffset + attractOffset;
    _sprite.move(moveOffset);
}

void Sheep::draw(sf::RenderWindow* const window) {
    window->draw(_sprite);
}

sf::FloatRect Sheep::getBounds() const {
    return _sprite.getGlobalBounds();
}

const sf::Vector2f& Sheep::getCenter() const {
    return _sprite.getPosition();
}
