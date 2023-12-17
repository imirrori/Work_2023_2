#include "game.h"

int main()
{
    Game game;
    InitGame(&game);
    StartGame(&game);
    DeinitGame(&game);
    return 0;
}
