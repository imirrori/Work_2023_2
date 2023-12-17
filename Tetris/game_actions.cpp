#include "game_actions.h"
#include "game_shower.h"

#include <ncurses.h>
#include <stdlib.h>

bool MenuAction(Game* game, std::chrono::milliseconds ms)
{
    if (ms.count() > 30) {
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
        return true;
    }
    return false;
}

bool GameAction(Game* game, std::chrono::milliseconds ms)
{
    if (game->current_figure == NONE) {
        game->current_x = 5;
        game->current_y = -4;
        game->current_figure = game->next_figure;
        game->next_figure = rand() % COUNT;
    }

    if (ms.count() > 300) {
        clear();
        ShowField(game);
        refresh();
        ++game->current_y;
        //если дошли до конца, сбросить.
        if (game->current_y > game->field.Height) {
            game->current_figure = NONE;
        }
        return true;
    }
    return false;
}
