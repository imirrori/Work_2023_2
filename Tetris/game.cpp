#include "game.h"

#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include <chrono>
#include <iostream>

void ThreanFunc(Game* game)
{
    if (game == nullptr) {
        return;
    }

    auto begin = std::chrono::steady_clock::now();
    while(game->current_state != IN_EXIT) {

        if (game->current_state == IN_GAME) {
            if (game->current_figure == NONE) {
                game->current_x = 5;
                game->current_y = -4;
                game->current_figure = game->next_figure;
                game->next_figure = rand() % COUNT;
            }
            const auto now = std::chrono::steady_clock::now();
            const auto diff = now - begin;

            if (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() > 300) {
                clear();
                ShowField(game);
                refresh();
                ++game->current_y;
                //если дошли до конца, сбросить.
                if (game->current_y > game->field.Height) {
                    game->current_figure = NONE;
                }

                begin = std::chrono::steady_clock::now();
            }
        } else if (game->current_state == IN_MENU) {
            const auto now = std::chrono::steady_clock::now();
            const auto diff = now - begin;
            if (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() > 30) {
                clear();
                attron(COLOR_PAIR(POLITRA_MENU));
                for (int i = 0; i < game->height; ++i) {
                    for (int j = 0; j < game->width; ++j) {
                        move(i, j);
                        addch(' ');
                    }
                }

                move(game->height / 2 - 1, game->width / 2 - 5);
                printw("%cStart game", game->current_menu_option == START_GAME ? '*' : ' ');
                move(game->height / 2 + 0, game->width / 2 - 5);
                printw("%cRecords", game->current_menu_option == RECORDS ? '*' : ' ');
                move(game->height / 2 + 1, game->width / 2 - 5);
                printw("%cExit", game->current_menu_option == EXIT ? '*' : ' ');
                attroff(COLOR_PAIR(POLITRA_MENU));
                refresh();
                begin = std::chrono::steady_clock::now();
            }
        }
    }
}

void PrintFigurePoint(int figure, int x, int y)
{
    if (Figures[figure].values[x][y]) {
        attron(COLOR_PAIR(POLITRA_FIGURE));
    } else {
        attron(COLOR_PAIR(POLITRA_FIELD));
    }
    addch(' ');
    if (Figures[figure].values[x][y]) {
        attroff(COLOR_PAIR(POLITRA_FIGURE));
    } else {
        attroff(COLOR_PAIR(POLITRA_FIELD));
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
    game->current_menu_option = START_GAME;

    game->next_figure = rand() % COUNT;
    game->current_figure = NONE;
    game->current_x = -4;
    game->current_y = 5;
    game->figure_speed = 1;

    game->current_state = IN_MENU;

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    getmaxyx(stdscr, game->height, game->width);

    InitPolitra();

    game->th = new std::thread(ThreanFunc, game);
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

    int ch;
    do {
        ch = getch();

        switch(ch)
        {
            case 10: //KEY_ENTER
            {
                if (game->current_menu_option == EXIT)
                {
                    game->current_state = IN_EXIT;
                }
                else if (game->current_menu_option == START_GAME)
                {
                    game->current_state = IN_GAME;
                }
                break;
            }
            case KEY_DOWN:
            {
                game->current_menu_option += 1;
                if (game->current_menu_option > EXIT) {
                    game->current_menu_option = START_GAME;
                }
                break;
            }
            case KEY_UP:
            {
                game->current_menu_option -= 1;
                if (game->current_menu_option < START_GAME) {
                    game->current_menu_option = EXIT;
                }
                break;
            }
        }
    } while (game->current_state != IN_EXIT);
}

void ShowField(Game* game)
{
    if (game == nullptr) {
        return;
    }

    attron(COLOR_PAIR(POLITRA_FIELD));
    move(0, 1);
    printw("+------------------+");
    for (int j = 0; j < Field::Height; ++j) {
        move(j + 1, 1);
        addch('|');
        for (int i = 0; i < Field::Width; ++i) {
            const int diff_i = i + 1;
            const int diff_j = j + 2;
            if (game->field.data[i][j] ||
                (diff_i >= game->current_x && diff_i <= game->current_x + 3 &&
                 diff_j >= game->current_y && diff_j <= game->current_y + 3 &&
                 (diff_j - game->current_y >= 0)))
            {
                PrintFigurePoint(
                    game->current_figure,
                    diff_i - game->current_x,
                    diff_j - game->current_y);
            } else {
                addch(' ');
            }
        }
        addch('|');
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
            PrintFigurePoint(game->next_figure, i, j);
        printw("       |");
    }
    move(8, 21);
    printw("|              |");
    move(9, 21);
    printw("+--------------+");

    attroff(COLOR_PAIR(POLITRA_FIELD));
}
