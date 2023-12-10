#ifndef GAME_H
#define GAME_H

#include "figures.h"

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

struct Game
{
    int width;
    int height;
    int currentMenuOption;
    int cuurent_figure;
};

void InitGame(Game* game);
void DeinitGame(Game* game);

void ShowScreensaver(Game* game);
void ShowMenu(Game* game);
void ShowField(Game* game);

#endif // GAME_H
