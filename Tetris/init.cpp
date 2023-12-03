#include "init.h"

#include <ncurses.h>

void Init(Game* game)
{
    if (game == nullptr) {
        return;
    }

    initscr();
    getmaxyx(stdscr, game->height, game->width);
}

void Deinit()
{
    endwin();
}
