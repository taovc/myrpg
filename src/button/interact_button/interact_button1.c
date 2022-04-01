/*
** EPITECH PROJECT, 2021
** interact_button1.c
** File description:
** my_rpg
*/

#include "gamesys.h"
#include "./button/button_script.h"

void interact_button(game_t *gm, void *scene, buttons_t *button)
{
    draw_buttons(gm, button);
    click_on_button(gm, scene, button);
}