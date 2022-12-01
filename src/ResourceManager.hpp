#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager {
private:
    std::unordered_map<std::string, sf::Texture*> _textures;
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    sf::Texture* const getTexture(const std::string& identifier) const;

    void addTexture(const std::string& textureFileName, const std::string& identifier);
    void removeTexture(const std::string& identifier);
};

#endif