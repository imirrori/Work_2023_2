#include "game_shower.h"

#include <ncurses.h>

void ShowFigurePoint(Figure figure, int x, int y)
{
    if (figure.values[y][x]) {
        attron(COLOR_PAIR(POLITRA_FIGURE));
    } else {
        attron(COLOR_PAIR(POLITRA_FIELD));
    }
    addch(' ');
    if (figure.values[y][x]) {
        attroff(COLOR_PAIR(POLITRA_FIGURE));
    } else {
        attroff(COLOR_PAIR(POLITRA_FIELD));
    }
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
            const int diff_i = i;
            const int diff_j = j + 2;
            if (game->field.data[i][j] ||
                (diff_i >= game->current_figure.x && diff_i <= game->current_figure.x + 3 &&
                 diff_j >= game->current_figure.y && diff_j <= game->current_figure.y + 3 &&
                 (diff_j - game->current_figure.y >= 0)))
            {
                ShowFigurePoint(
                    game->current_figure.data,
                    diff_i - game->current_figure.x,
                    diff_j - game->current_figure.y);
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
            ShowFigurePoint(
                Figures[game->next_figure],
                i,
                j);
        printw("       |");
    }
    move(8, 21);
    printw("|              |");
    move(9, 21);
    printw("+--------------+");

    attroff(COLOR_PAIR(POLITRA_FIELD));
}
