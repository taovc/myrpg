/*
** EPITECH PROJECT, 2021
** free_npc
** File description:
** free npc
*/

#include "gamesys.h"
#include "./gameplay/gameplay_struct.h"
#include <stdlib.h>

void free_npc(npc_t **npc)
{
    for (int i = 0; npc[i]; ++i) {
        sfFont_destroy(npc[i]->font);
        sfText_destroy(npc[i]->dialog);
        sfSprite_destroy(npc[i]->sprite);
        sfTexture_destroy(npc[i]->texture);
        free(npc[i]);
    }
    free(npc);
}