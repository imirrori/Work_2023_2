#ifndef GAME_H
#define GAME_H

#include "figures.h"

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

    int next_figure;
    int current_figure;
    int current_x;
    int current_y;
    int figure_speed;

    int current_state;
    std::thread* th;
};

void InitGame(Game* game);
void DeinitGame(Game* game);

void ShowScreensaver(Game* game);
void ShowMenu(Game* game);
void ShowField(Game* game);

#endif // GAME_H
