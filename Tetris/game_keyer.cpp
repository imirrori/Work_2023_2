#include "game_keyer.h"

#include <ncurses.h>

void MenuKeyer(Game* game, int ch)
{
    switch(ch)
    {
        case 10: //KEY_ENTER
        {
            if (game->current_menu_option == EXIT)
            {
                game->current_state = IN_EXIT;
            }
            else if (game->current_menu_option == START_GAME)
            {
                game->current_state = IN_GAME;
            }
            break;
        }
        case KEY_DOWN:
        {
            game->current_menu_option += 1;
            if (game->current_menu_option > EXIT) {
                game->current_menu_option = START_GAME;
            }
            break;
        }
        case KEY_UP:
        {
            game->current_menu_option -= 1;
            if (game->current_menu_option < START_GAME) {
                game->current_menu_option = EXIT;
            }
            break;
        }
    }
}

void GameKeyer(Game*, int)
{

}
