#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML\Graphics.hpp>
#include <string>

/**
 * @brief An interactive button.
 * 
 * @author aCallin
 */
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
    /**
     * @brief Construct a Button object. Generally, after a button is created, setTexturePaths() should be called 
     * before any other Button methods.
     */
    Button();

    /**
     * @brief Destroy the Button object.
     */
    ~Button() = default;

    /**
     * @brief Update the internal state of the button.
     * 
     * @param window the RenderWindow being used
     */
    void update(const sf::RenderWindow& window);

    /**
     * @brief Display the button.
     * 
     * @param window the RenderWindow to draw to
     */
    void draw(sf::RenderWindow* const window);

    /**
     * @brief Returns whether the button was clicked (pressed and released). The mouse has to be hovered over the 
     * button for the entire duration that the button was released, pressed, then released again, for it to be 
     * considered clicked.
     * 
     * @return true if the button was clicked, false otherwise
     */
    bool wasClicked() const;

    /**
     * @brief Get the size of the button, accounting for transformations applied to the button.
     * 
     * @return sf::Vector2f the size of the button
     */
    sf::Vector2f getSize() const;
    
    /**
     * @brief Get the position of the button.
     * 
     * @return const sf::Vector2f& the position of the button
     */
    const sf::Vector2f& getPosition() const;

    /**
     * @brief Set the default, hovered, and pressed textures of the button. These textures should be the same size. The 
     * pressed texture is drawn when the button is pressed, hovered when the button is hovered over but not pressed, 
     * and default otherwise.
     * 
     * @param defaultTexturePath where to find the button's default texture
     * @param hoveredTexturePath where to find the button's hovered texture
     * @param pressedTexturePath where to find the button's pressed texture
     */
    void setTexturePaths(std::string defaultTexturePath, 
                         std::string hoveredTexturePath, 
                         std::string pressedTexturePath);

    /**
     * @brief Set the position of the button.
     * 
     * @param position the position of the button
     */
    void setPosition(const sf::Vector2f& position);

    /**
     * @brief Set the scale of the button.
     * 
     * @param scaleFactors the x and y scale factors
     */
    void setScale(const sf::Vector2f& scaleFactors);
};

#endif