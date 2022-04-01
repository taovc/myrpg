/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** choose fps
*/

#include "./menu/menu_struct.h"

void low_fps(game_t *gm, menu_t *mn)
{
    mn->fps = 30;
    sfRenderWindow_setFramerateLimit(gm->window, mn->fps);
}

void medium_fps(game_t *gm, menu_t *mn)
{
    mn->fps = 60;
    sfRenderWindow_setFramerateLimit(gm->window, mn->fps);
}

void high_fps(game_t *gm, menu_t *mn)
{
    mn->fps = 120;
    sfRenderWindow_setFramerateLimit(gm->window, mn->fps);
}

void sound_off(game_t *gm)
{
    if (gm->music_open == 1)
        gm->music_open = 0;
    else
        gm->music_open = 1;
}