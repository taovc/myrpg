/*
** EPITECH PROJECT, 2021
** equip_item
** File description:
** Equip or unequip items
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"

void throw(play_t *game, int item)
{
    insert_item(game->inventories->inventory[item], 0, item, game->button);
}

void unequip_item(game_t *gm, play_t *game, int part)
{
    insert_item(game->inventories->inventory[gm->last_item],
    game->inventories->equip_inventory[part]->item_id, gm->last_item,
    game->button);
    game->stats->hp_max -=
    item_arr[game->inventories->equip_inventory[part]->item_id].hp;
    game->stats->atck -=
    item_arr[game->inventories->equip_inventory[part]->item_id].attack;
    game->stats->def -=
    item_arr[game->inventories->equip_inventory[part]->item_id].def;
    update_inv_stat(game->inventories->inv_stat, game->stats);
    search_last_item(game->inventories->inventory, gm);
    insert_equip_item(game->inventories->equip_inventory[part], 0, part,
    game->button);
}

void equip_on_player(game_t *gm, play_t *game, int item, int slot)
{
    unequip_item(gm, game, slot);
    insert_equip_item(game->inventories->equip_inventory[slot],
    game->inventories->inventory[item]->item_id, slot, game->button);
    throw(game, item);
    search_last_item(game->inventories->inventory, gm);
}

void equip(game_t *gm, play_t *game, int item)
{
    if (game->combat->in_combat == 1)
        return;
    game->stats->atck +=
    item_arr[game->inventories->inventory[item]->item_id].attack;
    game->stats->def +=
    item_arr[game->inventories->inventory[item]->item_id].def;
    game->stats->hp_max +=
    item_arr[game->inventories->inventory[item]->item_id].hp;
    if (game->inventories->inventory[item]->type == sword)
        equip_on_player(gm, game, item, 0);
    if (game->inventories->inventory[item]->type == chest)
        equip_on_player(gm, game, item, 3);
    update_inv_stat(game->inventories->inv_stat, game->stats);
    sfMusic_stop(game->music->sound_eff[3]->music);
    sfMusic_play(game->music->sound_eff[3]->music);
}