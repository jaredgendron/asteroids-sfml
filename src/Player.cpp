#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.hpp"
#include "main.hpp"

Player::Player() : _sprite()
{
    _sprite.setPointCount(4);
    _sprite.setOutlineThickness(3);
    _sprite.setPoint(0, sf::Vector2f(0.0f, -20.0f));
    _sprite.setPoint(1, sf::Vector2f(-15.0f, 20.0f));
    _sprite.setPoint(2, sf::Vector2f(0.0f, 17.0f));
    _sprite.setPoint(3, sf::Vector2f(15.0f, 20.0f));
    _sprite.setFillColor(sf::Color(0, 0, 0, 0));
    _sprite.setOutlineColor(sf::Color::White);

    controls[0] = sf::Keyboard::W;
    controls[1] = sf::Keyboard::A;
    controls[2] = sf::Keyboard::D;
}

Player::Player(sf::Color color,sf::Keyboard::Key up, sf::Keyboard::Key left, sf::Keyboard::Key right) : _sprite()
{
    _sprite.setPointCount(4);
    _sprite.setOutlineThickness(3);
    _sprite.setPoint(0, sf::Vector2f(0.0f, -20.0f));
    _sprite.setPoint(1, sf::Vector2f(-15.0f, 20.0f));
    _sprite.setPoint(2, sf::Vector2f(0.0f, 17.0f));
    _sprite.setPoint(3, sf::Vector2f(15.0f, 20.0f));
    _sprite.setFillColor(sf::Color(0, 0, 0, 0));
    _sprite.setOutlineColor(color);
    
    controls[0] = up;
    controls[1] = left;
    controls[2] = right;
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    if(rotation != 0)
    {
        float angle = rotation*180*seconds;
        _sprite.rotate(angle);
    }
    if(isMoving)
    {
        float angle = _sprite.getRotation() / 180*M_PI - M_PI/2;
        _velocity += sf::Vector2f(std::cos(angle),std::sin(angle))*60.f*seconds;
    }
    _sprite.move(seconds*_velocity);
    sf::Vector2f position = _sprite.getPosition();

    if (position.x < -10.0f)
        position.x = WIDTH;
    else if (position.x > WIDTH)
        position.x = 0.0f;

    if (position.y < -10.0f)
        position.y = HEIGHT;
    else if (position.y > HEIGHT)
        position.y = 0.0f;
    setPosition(position);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite,states);
}

void Player::processEvents()
{
    isMoving = sf::Keyboard::isKeyPressed(controls[0]);
    rotation = 0;
    rotation-= sf::Keyboard::isKeyPressed(controls[1]);
    rotation+= sf::Keyboard::isKeyPressed(controls[2]);
}