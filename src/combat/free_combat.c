/*
** EPITECH PROJECT, 2021
** free_combat
** File description:
** Free combat
*/

#include <stdlib.h>
#include "./gameplay/gameplay_struct.h"

void free_combat_target(combat_t *combat)
{
    if (combat->cross || combat->target) {
        sfTexture_destroy(combat->cross);
        sfSprite_destroy(combat->target);
    }
}

void free_combat_mobs(combat_t *combat)
{
    if (combat->mobs == NULL || combat->in_combat == 0)
        return;
    for (int i = 0; combat->mobs[i]; ++i) {
        if (combat->mobs[i]->mobs) {
            sfSprite_destroy(combat->mobs[i]->mobs);
        }
        sfTexture_destroy(combat->mobs[i]->texture);
        sfTexture_destroy(combat->mobs[i]->hp_bar->hp_text);
        sfTexture_destroy(combat->mobs[i]->hp_bar->hpb_text);
        sfSprite_destroy(combat->mobs[i]->hp_bar->hp);
        sfSprite_destroy(combat->mobs[i]->hp_bar->hp_bar);
        free(combat->mobs[i]->hp_bar);
        free(combat->mobs[i]);
    }
    free_combat_target(combat);
    if (combat->mobs) {
        free(combat->mobs);
        combat->mobs = NULL;
    }
    combat->in_combat = 0;
}

void free_combat(combat_t *combat)
{
    if (!combat)
        return;
    if (combat->player) {
        sfSprite_destroy(combat->player->player);
        sfTexture_destroy(combat->player->texture);
        free(combat->player);
    }
    free(combat);
}