#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML\Graphics.hpp>
#include <string>

class Button {
private:
    sf::Texture _defaultTexture;
    sf::Texture _hoveredTexture;
    sf::Texture _pressedTexture;
    sf::Sprite _sprite;
    bool _wasEntered;
    bool _isHoveredOver;
    bool _wasDraggedOver;
    bool _isPressed;
    bool _wasClicked;

    bool checkIsHoveredOver(const sf::RenderWindow& window);
    bool checkIsPressed();
    void setSpriteTexture(const sf::Texture& texture);
public:
    Button();
    ~Button() = default;

    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow* const window);

    /**
     * @brief Returns whether the button was clicked (pressed and released). The mouse has to be hovered over the 
     * button for the entire duration that the button was released, pressed, then released again, for it to be 
     * considered clicked.
     * 
     * @return true if the button was clicked, false otherwise.
     */
    bool wasClicked() const;

    /**
     * @brief Get the size of the button, accounting for transformations applied to the button.
     * 
     * @return sf::Vector2f the size of the button.
     */
    sf::Vector2f getSize() const;
    
    /**
     * @brief Get the position of the button.
     * 
     * @return const sf::Vector2f& the position of the button.
     */
    const sf::Vector2f& getPosition() const;

    void setTexturePaths(std::string defaultTexturePath, 
                         std::string hoveredTexturePath, 
                         std::string pressedTexturePath);
    void setPosition(const sf::Vector2f& position);
    void setScale(const sf::Vector2f& scaleFactors);
};

#endif