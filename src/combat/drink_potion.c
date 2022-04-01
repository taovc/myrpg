/*
** EPITECH PROJECT, 2021
** drink_potion
** File description:
** drink potion
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"
#include "./button/button_script.h"

void drink_potion(game_t *gm, play_t *game)
{
    for (int i = 0; i < NBR_ITEM; ++i) {
        if (game->inventories->inventory[i]->type == usable) {
            update_type(gm, inventory);
            update_inv_stat(game->inventories->inv_stat, game->stats);
            break;
        }
    }
}