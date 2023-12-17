#ifndef GAME_H
#define GAME_H

#include "figures.h"
#include "field.h"

#include <thread>

enum POLITRA
{
    POLITRA_SCRENSERVER = 1,
    POLITRA_MENU,
    POLITRA_FIELD,
    POLITRA_FIGURE,
};

enum MENU
{
    START_GAME,
    RECORDS,
    EXIT
};

enum GAME_STATE
{
    IN_MENU,
    IN_GAME,
    IN_EXIT
};

struct Game
{
    int width;
    int height;
    int current_menu_option;
    Field field;
    CurrentFigure current_figure;

    int next_figure;
    int figure_speed;

    int current_state;
    std::thread* th;
};

void InitGame(Game* game);
void DeinitGame(Game* game);

void StartGame(Game* game);

#endif // GAME_H
