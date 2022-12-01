#include "ResourceManager.hpp"

sf::Texture* const ResourceManager::getTexture(const std::string& identifier) const {
    return _textures.at(identifier);
}

void ResourceManager::addTexture(const std::string& textureFileName, const std::string& identifier) {
    if (_textures.find(identifier) == _textures.end()) {
        sf::Texture* texture = new sf::Texture();
        texture->loadFromFile("res/textures/" + textureFileName);
        _textures.insert({identifier, texture});
    }
}

void ResourceManager::removeTexture(const std::string& identifier) {
    sf::Texture* texture = _textures.at(identifier);
    delete texture;
    _textures.erase(identifier);
}
