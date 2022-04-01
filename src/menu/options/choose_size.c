/*
** EPITECH PROJECT, 2021
** choose size window
** File description:
** rpg
*/

#include "./menu/menu_struct.h"
#include "./button/button_script.h"

void small_window_size(game_t *gm)
{
    sfVector2u size;
    size.x = 800;
    size.y = 600;

    sfRenderWindow_setSize(gm->window, size);
}

void medium_window_size(game_t *gm)
{
    sfVector2u size;
    size.x = 1400;
    size.y = 900;

    sfRenderWindow_setSize(gm->window, size);
}

void high_window_size(game_t *gm)
{
    sfVector2u size;
    size.x = 1920;
    size.y = 1080;

    sfRenderWindow_setSize(gm->window, size);
}
