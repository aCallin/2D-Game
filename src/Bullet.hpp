#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML\Graphics.hpp>

class Bullet {
private:
    sf::CircleShape _shape;
    sf::Vector2f _direction;
    float _speed;
    int _age;
public:
    Bullet(const sf::Vector2f& position, const sf::Vector2f& direction, float speed, float radius, 
           const sf::Color& color);
    ~Bullet() = default;

    const sf::CircleShape& getShape() const;
    const sf::Vector2f& getDirection() const;
    float getSpeed() const;
    int getAge() const;

    void setAge(int age);
};

#endif
