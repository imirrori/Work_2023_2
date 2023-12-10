#include "game.h"

#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

void ThreanFunc(Game* game)
{
    if (game == nullptr) {
        return;
    }

    while(!game->is_exit)
    {

    }

}

void InitPolitra()
{
    start_color();
    init_pair(POLITRA_SCRENSERVER, COLOR_WHITE, COLOR_BLUE);
    init_pair(POLITRA_MENU, COLOR_WHITE, COLOR_BLACK);
    init_pair(POLITRA_FIELD, COLOR_WHITE, COLOR_BLACK);
    init_pair(POLITRA_FIGURE, COLOR_WHITE, COLOR_GREEN);
}

void InitGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    srand(time(NULL));

    game->height = 0;
    game->width = 0;
    game->currentMenuOption = START_GAME;
    game->next_figure = rand() % COUNT;
    game->current_figure = NONE;

    game->is_exit = false;
    game->th = new std::thread(ThreanFunc, game);

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    getmaxyx(stdscr, game->height, game->width);

    InitPolitra();
}

void DeinitGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    if (game->th && game->th->joinable())
    {
        game->th->join();
    }

    delete game->th;

    endwin();
}

void ShowScreensaver(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(POLITRA_SCRENSERVER));
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
    attroff(COLOR_PAIR(POLITRA_SCRENSERVER));

    getch();
}

void ShowMenu(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(POLITRA_MENU));
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
                    game->is_exit = true;
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

    attroff(COLOR_PAIR(POLITRA_MENU));
}

void ShowField(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(POLITRA_FIELD));
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
    move(3, 21);
    printw("|              |");
    for(int j = 0; j < 4; ++j)
    {
        move(4 + j, 21);
        printw("|   ");
        for(int i = 0; i < 4; ++i)
        {
            if (Figures[game->next_figure].values[i][j]) {
                attron(COLOR_PAIR(POLITRA_FIGURE));
            } else {
                attron(COLOR_PAIR(POLITRA_FIELD));
            }
            addch(' ');
            if (Figures[game->next_figure].values[i][j]) {
                attroff(COLOR_PAIR(POLITRA_FIGURE));
            } else {
                attroff(COLOR_PAIR(POLITRA_FIELD));
            }
        }
        printw("       |");
    }
    move(8, 21);
    printw("|              |");
    move(9, 21);
    printw("+--------------+");

    attroff(COLOR_PAIR(POLITRA_FIELD));
}
