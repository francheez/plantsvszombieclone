#include "../include/config.h"
#include "../include/game.h"

int main() {
    Game* game = new Game();

    if(game->init("My awful PVZ clone", WIN_WIDTH, WIN_HEIGHT) != 0) {
        return -1;
    }

    game->run();

    delete game;

    return 0;
}