#include "game.h"

void InitGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    game->height = 0;
    game->width = 0;
}
