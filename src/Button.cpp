#include "Button.hpp"

Button::Button() {
    _wasEntered = false;
    _isHoveredOver = false;
    _wasDraggedOver = false;
    _isPressed = false;
    _wasClicked = false;
}

void Button::update(const sf::RenderWindow& window) {
    if (_sprite.getTexture() == nullptr)
        return;

    // Compare the previous state of the mouse to the current state to determine the internal state of the button.
    _wasEntered = checkIsHoveredOver(window) && !_isHoveredOver;
    _isHoveredOver = checkIsHoveredOver(window);
    if (_wasEntered && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        _wasDraggedOver = true;
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        _wasDraggedOver = false;
    _wasClicked = _isHoveredOver && !sf::Mouse::isButtonPressed(sf::Mouse::Left) && _isPressed && !_wasDraggedOver;
    _isPressed = checkIsPressed() && !_wasDraggedOver;

    // Set the current texture.
    if (_isPressed)
        setSpriteTexture(*_pressedTexture);
    else if (_isHoveredOver)
        setSpriteTexture(*_hoveredTexture);
    else
        setSpriteTexture(*_defaultTexture);
}

void Button::draw(sf::RenderWindow* const window) {
    if (_sprite.getTexture() != nullptr)
        window->draw(_sprite);
}

bool Button::wasClicked() const {
    return _wasClicked;
}

sf::Vector2f Button::getSize() const {
    sf::FloatRect globalBounds = _sprite.getLocalBounds();
    return sf::Vector2f(globalBounds.width, globalBounds.height);
}

const sf::Vector2f& Button::getPosition() const {
    return _sprite.getPosition();
}

void Button::setTextures(const sf::Texture& defaultTexture, 
                         const sf::Texture& hoveredTexture, 
                         const sf::Texture& pressedTexture) {
    _defaultTexture = &defaultTexture;
    _hoveredTexture = &hoveredTexture;
    _pressedTexture = &pressedTexture;
    _sprite.setTexture(*_defaultTexture);
}

void Button::setPosition(const sf::Vector2f& position) {
    _sprite.setPosition(position);
}

bool Button::checkIsHoveredOver(const sf::RenderWindow& window) {
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::Vector2f buttonPosition = getPosition();
    sf::Vector2f buttonSize = getSize();

    float buttonLeft = buttonPosition.x;
    float buttonRight = buttonPosition.x + buttonSize.x;
    float buttonTop = buttonPosition.y;
    float buttonBottom = buttonPosition.y + buttonSize.y;
    return (mousePosition.x >= buttonLeft && mousePosition.x <= buttonRight && 
            mousePosition.y >= buttonTop && mousePosition.y <= buttonBottom);
}

bool Button::checkIsPressed() {
    return _isHoveredOver && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::setSpriteTexture(const sf::Texture& texture) {
    if (_sprite.getTexture() != &texture)
        _sprite.setTexture(texture, true);
}
