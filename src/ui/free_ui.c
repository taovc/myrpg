/*
** EPITECH PROJECT, 2021
** free_ui
** File description:
** Free ui
*/

#include "gamesys.h"
#include <stdlib.h>

void free_ui(ui_t **ui)
{
    for (int i = 0; ui[i]; ++i) {
        if (ui[i]->ui_sprite)
            sfSprite_destroy(ui[i]->ui_sprite);
        if (ui[i]->ui_texture)
            sfTexture_destroy(ui[i]->ui_texture);
        free(ui[i]);
    }
    free(ui);
}