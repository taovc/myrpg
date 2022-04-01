/*
** EPITECH PROJECT, 2021
** pause
** File description:
** Pause
*/

#include "gamesys.h"
#include "./button/button_script.h"

void stop_pause(game_t *gm)
{
    update_type(gm, gm->last_type);
}

void return_to_menu(game_t *gm)
{
    gm->now_parti = menu_parti;
    update_type(gm, menu);
}