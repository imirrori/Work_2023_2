#include "game.h"

int main()
{
    Game game;
    InitGame(&game);
    ShowScreensaver(&game);

    DeinitGame(&game);
    return 0;
}
