/*
** EPITECH PROJECT, 2021
** interact_item
** File description:
** Interact with items
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"
#include <stdio.h>

static void attack_players(game_t *gm, play_t *game)
{
    if (!game->combat->in_combat)
        return;
    for (int i = 0; game->combat->mobs[i]; ++i)
        if (attack_player(gm, game, i) == 1)
            break;
}

static void use(game_t *gm, play_t *game, int item)
{
    if (game->combat->in_combat == 1) {
        update_hp_bar(game->ui[2]->ui_sprite, &game->stats->hp, (sfVector2f)
        {game->stats->hp_max,
        -item_arr[game->inventories->inventory[item]->item_id].hp});
        update_type(gm, in_combat);
    } else {
        game->stats->hp +=
        item_arr[game->inventories->inventory[item]->item_id].hp;
        if (game->stats->hp > game->stats->hp_max)
            game->stats->hp = game->stats->hp_max;
    }
    update_inv_stat(game->inventories->inv_stat, game->stats);
    update_hp_bar(game->ui[2]->ui_sprite,
    &game->stats->hp, (sfVector2f){game->stats->hp_max, 0});
    insert_item(game->inventories->inventory[item], 0, item, game->button);
    search_last_item(game->inventories->inventory, gm);
    sfMusic_stop(game->music->sound_eff[2]->music);
    sfMusic_play(game->music->sound_eff[2]->music);
    attack_players(gm, game);
}

void interact_item(game_t *gm, play_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gm->window);
    int button = (mouse_pos.y - (int)game->button->buttons[1]->pos.y) / 30;
    int item = game->selectioned_item;

    if (button == 1)
        throw(game, item);
    if (button == 0 && game->inventories->inventory[item]->type == usable)
        use(gm, game, item);
    else if (button == 0 && game->inventories->inventory[item]->type != usable)
        equip(gm, game, item);
    game->button->buttons[0]->can_draw = DROW_TOUCH;
    game->button->buttons[1]->can_draw = CONST;
}