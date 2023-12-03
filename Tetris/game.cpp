#include "game.h"

#include <ncurses.h>

void InitPolitra()
{
    start_color();
    init_pair(SCRENSERVER, COLOR_WHITE, COLOR_BLUE);
    init_pair(MENU, COLOR_WHITE, COLOR_BLACK);
    init_pair(FIELD, COLOR_WHITE, COLOR_BLACK);
}

void InitGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    game->height = 0;
    game->width = 0;
    game->currentMenuOption = START_GAME;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    getmaxyx(stdscr, game->height, game->width);

    InitPolitra();
}

void DeinitGame(Game*)
{
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

    getch();
}

void ShowMenu(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(MENU));
    for (int i = 0; i < game->height; ++i) {
        for (int j = 0; j < game->width; ++j) {
            move(i, j);
            addch(' ');
        }
    }

    int ch;
    do {
        move(game->height / 2 - 1, game->width / 2 - 5);
        printw("%cStart game", game->currentMenuOption == START_GAME ? '*' : ' ');
        move(game->height / 2 + 0, game->width / 2 - 5);
        printw("%cRecords", game->currentMenuOption == RECORDS ? '*' : ' ');
        move(game->height / 2 + 1, game->width / 2 - 5);
        printw("%cExit", game->currentMenuOption == EXIT ? '*' : ' ');

        ch = getch();

        switch(ch)
        {
            case 10: //KEY_ENTER
            {
                if (game->currentMenuOption == EXIT)
                {
                    return;
                }
                else if (game->currentMenuOption == START_GAME)
                {
                    ShowField(game);
                }
                break;
            }
            case KEY_DOWN:
            {
                game->currentMenuOption += 1;
                if (game->currentMenuOption > EXIT) {
                    game->currentMenuOption = START_GAME;
                }
                break;
            }
            case KEY_UP:
            {
                game->currentMenuOption -= 1;
                if (game->currentMenuOption < START_GAME) {
                    game->currentMenuOption = EXIT;
                }
                break;
            }
        }
    } while (true);

    attroff(COLOR_PAIR(MENU));
}

void ShowField(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(FIELD));
    for (int i = 0; i < game->height; ++i) {
        for (int j = 0; j < game->width; ++j) {
            move(i, j);
            addch(' ');
        }
    }

    move(0, 1);
    printw("+------------------+");
    for (int i = 1; i < 23; ++i) {
        move(i, 1);
        printw("|                  |");
    }
    move(23, 1);
    printw("+------------------+");

    move(0, 21);
    printw("+--------------+");
    move(1, 21);
    printw("| Score: 0     |");
    move(2, 21);
    printw("+--------------+");

    attroff(COLOR_PAIR(FIELD));
}
