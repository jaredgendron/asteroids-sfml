#include <SFML/Graphics.hpp>
#include <iostream>
#include "Level.hpp"
#include "main.hpp"

Level::Level(int x,int y): _asteroid()
{
    for(int i=0; i<10; i++){
        _asteroid[i].setPosition(x+rnd(0,WIDTH/2),y+rnd(0,HEIGHT/2));
    }
}

void Level::update(sf::Time deltaTime)
{
    for(int i=0; i<10; i++){
        _asteroid[i].update(deltaTime);

        sf::Vector2f position = _asteroid[i].getPosition();
        positions[i] = sf::Vector2i(position);
        if (position.x < -50.0f)
            position.x = WIDTH+50;
        else if (position.x > WIDTH+50)
            position.x = -50.0f;

        if (position.y < -50.0f)
            position.y = HEIGHT+50;
        else if (position.y > HEIGHT+50)
            position.y = -50.0f;
        _asteroid[i].setPosition(position);
        // int xpos = _asteroid[i].getPosition().x;
        // int ypos = _asteroid[i].getPosition().y;
        // if (!(xpos*(xpos-WIDTH)<=0) | !(ypos*(ypos-HEIGHT)<=0)){
        //     _asteroid[i].setPosition(WIDTH/2,HEIGHT/2);
        // }
    }
    for(int j=0; j<10; j++){
        positions[j] = sf::Vector2i(0,0);
    }
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i=0; i<10; i++){
        target.draw(_asteroid[i]);
    }
}