#ifndef GAME_H
#define GAME_H

enum Politra
{
    SCRENSERVER = 1,
    MENU
};

enum Menu
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
};

void InitGame(Game* game);
void DeinitGame(Game* game);

void ShowScreensaver(Game* game);
void ShowMenu(Game* game);

#endif // GAME_H
