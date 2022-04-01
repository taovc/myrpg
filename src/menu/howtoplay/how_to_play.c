/*
** EPITECH PROJECT, 2021
** How to play
** File description:
** How to play menu
*/

#include "./menu/menu_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "./button/button_script.h"
#include "mysfmllib.h"

void go_to_how_to_play(game_t *gm)
{
    gm->type = menu_how_to_play;
}

void how_to_play(game_t *gm)
{
    gm->snd_click = music_click();
    gm->type = menu_how_to_play;
}