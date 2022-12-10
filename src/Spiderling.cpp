#include "Spiderling.hpp"

const float Spiderling::ShapeRadius = 30.0f;

Spiderling::Spiderling(const sf::Vector2f& position) {
    _shape.setPosition(position);
    _shape.setRadius(ShapeRadius);
    _shape.setOrigin(sf::Vector2f(ShapeRadius, ShapeRadius));
    _shape.setFillColor(sf::Color::Red);
}

void Spiderling::update(const sf::Vector2f& targetPosition) {
    _movementComponent.update(targetPosition, &_shape);
}

void Spiderling::draw(sf::RenderWindow* const window) {
    window->draw(_shape);
}
