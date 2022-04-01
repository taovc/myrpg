/*
** EPITECH PROJECT, 2021
** option
** File description:
** Option menu
*/

#include "./menu/menu_struct.h"
#include <stdio.h>
#include "./button/button_script.h"

void choose_fps(void)
{
    return;
}

void go_to_option(game_t *gm)
{
    gm->type = menu_options;
}

void back_to_menu(game_t *gm)
{
    gm->snd_click = music_click();
    gm->type = menu;
}

void option(game_t *gm)
{
    gm->snd_click = music_click();
    gm->type = menu_options;
}
