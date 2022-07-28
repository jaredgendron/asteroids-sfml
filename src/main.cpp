#include "Game.hpp"
#include <random>
#include "main.hpp"

//returns a random positive or negative integer between two given values
int rnd(int initial, int final)
{
    int rnd = (rand() % final + initial)*(rand() % 2 ? -1:1);
    return rnd;
}

int main()
{
    srand(time(NULL));

    Game game;
    game.run(FPS);

    return 0;
}