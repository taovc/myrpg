/*
** EPITECH PROJECT, 2021
** utilities
** File description:
** Fonction utile
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "gameplay/gameplay_struct.h"

void search_last_item(inventory_t **inventory, game_t *gm)
{
    for (int i = 0; i < NBR_ITEM; ++i)
        if (inventory[i]->type == nothing) {
            gm->last_item = i;
            break;
        }
}