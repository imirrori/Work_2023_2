#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "game.h"

#include <chrono>

bool MenuAction(Game* game, std::chrono::milliseconds ms);
bool GameAction(Game* game, std::chrono::milliseconds ms);

#endif // GAME_ACTIONS_H
