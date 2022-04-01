/*
** EPITECH PROJECT, 2021
** display_ui
** File description:
** Display the ui
*/

#include "gamesys.h"

void draw_ui(ui_t **ui, game_t *gm)
{
    for (int i = 0; ui[i]; ++i) {
        if (ui[i]->type == gm->type)
            sfRenderWindow_drawSprite(gm->window, ui[i]->ui_sprite, NULL);
    }
}