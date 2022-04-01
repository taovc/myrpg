/*
** EPITECH PROJECT, 2021
** combat_spritesheet
** File description:
** Move the spritesheets when in combat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void move_combat_spritesheet(game_t *gm, combat_t *combat)
{
    move_spritesheet(combat->player->player, &combat->player->rect,
        &combat->player->incre, combat->player->incre_limit);
    for (int i = 0; combat->mobs[i]; ++i) {
        if (combat->mobs[i]->mobs)
            move_spritesheet(combat->mobs[i]->mobs, &combat->mobs[i]->rect,
                &combat->mobs[i]->incre, combat->mobs[i]->incre_limit);
    }
}
