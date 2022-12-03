#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML\Graphics.hpp>

enum Source { player, enemy };

class Bullet {
private:
    sf::CircleShape _shape;
    sf::Vector2f _direction;
    float _speed;
    Source _source;
    int _age;
public:
    Bullet(const sf::Vector2f& position, const sf::Vector2f& direction, float speed, float radius, 
           const sf::Color& color, Source source);

    const sf::CircleShape& getShape() const;
    const sf::Vector2f& getDirection() const;
    float getSpeed() const;
    Source getSource() const;
    int getAge() const;

    void setAge(int age);

    void move(const sf::Vector2f& offset);
};

#endif
