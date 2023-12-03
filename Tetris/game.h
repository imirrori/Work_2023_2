#ifndef GAME_H
#define GAME_H

enum Politra
{
    SCRENSERVER = 1
};

struct Game
{
    int width;
    int height;
};

void InitGame(Game* game);
void DeinitGame(Game* game);

void ShowScreensaver(Game* game);

#endif // GAME_H
