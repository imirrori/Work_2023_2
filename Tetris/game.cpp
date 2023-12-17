#include "game.h"
#include "game_actions.h"
#include "game_keyer.h"
#include "game_shower.h"

#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include <chrono>

void ThreanFunc(Game* game)
{
    if (game == nullptr) {
        return;
    }

    auto begin = std::chrono::steady_clock::now();
    while(game->current_state != IN_EXIT) {
        const auto now = std::chrono::steady_clock::now();
        const auto diff = now - begin;
        bool is_cation = false;
        switch (game->current_state) {
            case IN_GAME:
                is_cation = GameAction(game, std::chrono::duration_cast<std::chrono::milliseconds>(diff));
                break;
            case IN_MENU:
                is_cation = MenuAction(game, std::chrono::duration_cast<std::chrono::milliseconds>(diff));
        }
        if (is_cation) {
            begin = std::chrono::steady_clock::now();
        }
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


void StartGame(Game* game)
{
    if (game == nullptr) {
        return;
    }

    //ShowScreensaver(&game);

    int ch;
    do {
        ch = getch();
        switch(game->current_state) {
            case IN_MENU:
                MenuKeyer(game, ch);
                break;
            case IN_GAME:
                GameKeyer(game, ch);
                break;
        }
    } while (game->current_state != IN_EXIT);
}

