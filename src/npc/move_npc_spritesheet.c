/*
** EPITECH PROJECT, 2021
** move_npc_spritesheet
** File description:
** move the npcs spritesheet
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void move_npc_spritesheet(game_t *gm, play_t *game)
{
    for (int i = 0; game->npc[i]; ++i)
        if (game->npc[i]->zone == gm->zone)
            move_spritesheet(game->npc[i]->sprite, &game->npc[i]->rect,
            &game->npc[i]->incre, game->npc[i]->incre_limit);
    for (int i = 0; game->npc[i]; ++i)
        if (gm->zone == game->npc[i]->zone) {
            sfRenderWindow_drawSprite(gm->window, game->npc[i]->sprite, NULL);
            sfRenderWindow_drawText(gm->window, game->npc[i]->dialog, NULL);
        }
}