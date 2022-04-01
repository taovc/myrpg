/*
** EPITECH PROJECT, 2021
** save_inventory
** File description:
** Save the inventory
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "gameplay/gameplay.h"
#include <stdlib.h>

int *construct_arr_from_inventory(play_t *game)
{
    int limit = NBR_ITEM + EQUIPPED_ITEM;
    int *arr = malloc(sizeof(int) * limit);

    for (int i = 0; i < NBR_ITEM; ++i)
        arr[i] = game->inventories->inventory[i]->item_id;
    for (int i = NBR_ITEM, s = 0; s < EQUIPPED_ITEM; ++i, ++s)
        arr[i] = game->inventories->equip_inventory[s]->item_id;
    return arr;
}

void save_inventory(play_t *game, FILE *file)
{
    int *arr = construct_arr_from_inventory(game);

    save_arr(file, arr, NBR_ITEM + EQUIPPED_ITEM, "save_inventory");
    fwrite(",\n", sizeof(char) * 2, 1, file);
}