/*
** EPITECH PROJECT, 2021
** init_inventory
** File description:
** Init the inventory
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "my.h"
#include <stdlib.h>
#include "./gameplay/gameplay.h"

static inventory_t **init_item_inventory(save_t *save, buttons_t *button)
{
    inventory_t **inventory = malloc(sizeof(inventory_t *) * (NBR_ITEM + 1));

    inventory[NBR_ITEM] = NULL;
    for (int i = 0, item_id = 0; i < NBR_ITEM; ++i) {
        inventory[i] = malloc(sizeof(inventory_t));
        item_id = save->item_id[i];
        insert_item(inventory[i], item_id, i, button);
    }
    return inventory;
}

static equipped_inventory_t **init_equipped_inventory(save_t *save,
buttons_t *button)
{
    equipped_inventory_t **equip_inventory =
    malloc(sizeof(equipped_inventory_t *) * (EQUIPPED_ITEM + 1));

    equip_inventory[EQUIPPED_ITEM] = NULL;
    for (int i = 0, s = NBR_ITEM, item_id = 0; i < EQUIPPED_ITEM; ++i, ++s) {
        equip_inventory[i] = malloc(sizeof(equipped_inventory_t));
        equip_inventory[i]->item = malloc(sizeof(item_t));
        item_id = save->item_id[s];
        equip_inventory[i]->item->type = 0;
        insert_equip_item(equip_inventory[i], item_id, i, button);
    }
    return equip_inventory;
}

void init_inventory(game_t *gm, play_t *game, save_t *save)
{
    game->inventories = malloc(sizeof(all_inventory_t));
    game->inventories->inventory = init_item_inventory(save, game->button);
    game->inventories->equip_inventory =
    init_equipped_inventory(save, game->button);
    search_last_item(game->inventories->inventory, gm);
    game->inventories->inv_stat =
    init_inventory_stat(game->button, game->stats);
}