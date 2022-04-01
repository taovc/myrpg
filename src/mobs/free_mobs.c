/*
** EPITECH PROJECT, 2021
** free_mobs
** File description:
** Free mobs
*/

#include "gamesys.h"
#include "./gameplay/gameplay_struct.h"
#include "./gameplay/mobs_struct.h"
#include <stdlib.h>

void free_mobs(mob_list_t *mobs)
{
    for (int i = 0; mobs->mobs_list[i]; ++i) {
        sfTexture_destroy(mobs->mobs_list[i]->texture);
        sfSprite_destroy(mobs->mobs_list[i]->mobs);
        free(mobs->mobs_list[i]);
    }
    free(mobs->mobs_list);
    free(mobs);
}