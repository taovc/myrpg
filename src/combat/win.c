/*
** EPITECH PROJECT, 2021
** win
** File description:
** Win
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"

void give_item(game_t *gm, play_t *game, int item_id)
{
    insert_item(game->inventories->inventory[gm->last_item],
        item_id, gm->last_item, game->button);
    search_last_item(game->inventories->inventory, gm);
}

void win(game_t *gm, play_t *game)
{
    free_combat_mobs(game->combat);
    update_type(gm, game->combat->last_type);
    if (game->map->next)
        game->map->leave = can_leave;
    reward(gm, game);
    game->combat->in_combat = 0;
}

void loose(game_t *gm, play_t *game)
{
    dead_animation(gm, game);
    respawn(gm, game);
}

void kill_mobs(game_t *gm, play_t *game, int target)
{
    sfSprite_destroy(game->combat->mobs[target]->mobs);
    game->combat->mobs[target]->mobs = NULL;
    if (game->map->tag == 4)
        gain_exp(game, 200);
    else
        gain_exp(game, 30);
}
