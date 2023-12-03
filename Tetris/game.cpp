#include "game.h"

#include <ncurses.h>

void InitPolitra()
{
    start_color();
    init_pair(SCRENSERVER, COLOR_WHITE, COLOR_BLUE);
}

void InitGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    game->height = 0;
    game->width = 0;

    initscr();
    noecho();
    curs_set(0);

    getmaxyx(stdscr, game->height, game->width);

    InitPolitra();
}

void DeinitGame(Game*)
{
    getch();
    endwin();
}

void ShowScreensaver(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(SCRENSERVER));
    for (int i = 0; i < game->height; ++i) {
        for (int j = 0; j < game->width; ++j) {
            move(i, j);
            addch('*');
        }
    }
    move(game->height / 2 - 1, game->width / 2 - 20);
    printw("     *     *     *     *     **     ");
    move(game->height / 2 + 0, game->width / 2 - 20);
    printw("** *** ******* *** *** *** **** ****");
    move(game->height / 2 + 1, game->width / 2 - 20);
    printw("** ***     *** ***  ****** ****     ");
    move(game->height / 2 + 2, game->width / 2 - 20);
    printw("** *** ******* ***  ****** ******** ");
    move(game->height / 2 + 3, game->width / 2 - 20);
    printw("** ***     *** *** **  *     **     ");
    attroff(COLOR_PAIR(SCRENSERVER));
}
