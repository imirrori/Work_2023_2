#include "game.h"
#include "init.h"

int main()
{
  Game game;

  InitGame(&game);
  Init(&game);


  Deinit();
  return 0;
}
