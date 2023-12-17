#include "game_actions.h"
#include "game_shower.h"

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

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
    if (game->current_figure.type == NONE) {
        game->current_figure.x = 9;
        game->current_figure.y = -4;
        game->current_figure.type = game->next_figure;
        game->current_figure.data.values = Figures[game->next_figure].values;
        game->next_figure = rand() % COUNT;
        game->figure_speed = 1;
    }

    const int map[5] =
    {
        300,
        200,
        100,
        50,
        10,
    };

    if (ms.count() > map[game->figure_speed - 1]) {
        clear();
        ShowField(game);
        refresh();
        ++game->current_figure.y;
        //если дошли до конца, сбросить.
        if (game->current_figure.y > game->field.Height) {
            game->current_figure.type = NONE;
        }
        return true;
    }
    return false;
}
