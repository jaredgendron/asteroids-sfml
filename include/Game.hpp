#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Level.hpp"

class Game {
    public:
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game();
        void run(int minimum_frame_per_seconds);
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        sf::RenderWindow _window;
        Player _player; //_player2;
        Level _level;
};