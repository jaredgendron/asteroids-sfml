#include <SFML/Graphics.hpp>
#include <random>
#include "Asteroid.hpp"
#include "main.hpp"

Asteroid::Asteroid() : _sprite()
{
    _sprite.setPointCount(8);
    _sprite.setOutlineThickness(3);

    int pts[10] = {0,-25,-40,-25,0,25,40,25,0,-25}; //circular points

    //set points by adding random variation
    for(int i=0;i<8;i++){
        _sprite.setPoint(i, sf::Vector2f(pts[i]+rnd(2,10),pts[i+2]+rnd(2,10)));
    }

    _sprite.setFillColor(sf::Color(0, 0, 0, 0));
    _sprite.setOutlineColor(sf::Color::White);

    rotation = rnd(1,1);
    x_vel = rnd(20,40);
    y_vel = rnd(20,40);
}

Asteroid::~Asteroid() {}

void Asteroid::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    float angle = rotation*180*seconds/(rand() % 5 + 2);
    _sprite.rotate(angle);
    _velocity = sf::Vector2f(x_vel,y_vel);

    _sprite.move(seconds*_velocity);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite,states);
}