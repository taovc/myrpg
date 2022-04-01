/*
** EPITECH PROJECT, 2021
** free_inventory
** File description:
** Free the inventory
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "./gameplay/gameplay_struct.h"
#include <stdlib.h>

static void free_item_inventory(inventory_t **inventory)
{
    for (int i = 0; inventory[i]; ++i) {
        sfSprite_destroy(inventory[i]->sprite);
        sfTexture_destroy(inventory[i]->texture);
        free(inventory[i]);
    }
    free(inventory);
}

static void free_equipped_inventory(equipped_inventory_t **inventory)
{
    for (int i = 0; inventory[i]; ++i) {
        free(inventory[i]->item);
        sfSprite_destroy(inventory[i]->sprite);
        sfTexture_destroy(inventory[i]->texture);
        free(inventory[i]);
    }
    free(inventory);
}

static void free_inventory_stat(inventory_stat_t *stat)
{
    sfFont_destroy(stat->font);
    sfText_destroy(stat->def);
    sfText_destroy(stat->dmg);
    sfText_destroy(stat->max_hp);
    sfText_destroy(stat->lvl);
    free(stat);
}

void free_inventory(all_inventory_t *inventories)
{
    free_equipped_inventory(inventories->equip_inventory);
    free_item_inventory(inventories->inventory);
    free_inventory_stat(inventories->inv_stat);
    free(inventories);
}