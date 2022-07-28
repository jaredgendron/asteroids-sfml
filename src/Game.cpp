#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "main.hpp"

Game::Game() : _window(sf::VideoMode(WIDTH,HEIGHT),TITLE), _player(), _level(WIDTH/2,HEIGHT/2)
//_player2(sf::Color::Red,sf::Keyboard::Up, sf::Keyboard::Left, sf::Keyboard::Right)
{
    _player.setPosition(WIDTH/4,HEIGHT/2);
    //_player2.setPosition(_window.getSize().x/4*3,_window.getSize().y/2);
}

void Game::run(int minimum_frame_per_seconds)
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    sf::Time TimePerFrame = sf::seconds(1.f/minimum_frame_per_seconds);

    while (_window.isOpen())
    {
        processEvents();
        timeSinceLastUpdate = clock.restart();

        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            update(TimePerFrame);
        }
        update(timeSinceLastUpdate);
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while(_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) 
            _window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
    }
    _player.processEvents();
    //_player2.processEvents();
}

void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);
    _level.update(deltaTime);
    //_player2.update(deltaTime);
}

void Game::render() {
    _window.clear();
    _window.draw(_player);
    _window.draw(_level);
    //_window.draw(_player2);
    _window.display();
}
