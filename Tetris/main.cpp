#include "game.h"

int main()
{
    Game game;
    InitGame(&game);
    ShowScreensaver(&game);
    ShowMenu(&game);

    DeinitGame(&game);
    return 0;
}
