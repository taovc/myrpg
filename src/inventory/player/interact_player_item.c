/*
** EPITECH PROJECT, 2021
** interact_player_item
** File description:
** Interact with the equipped item of the player
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "./gameplay/gameplay.h"

void interact_equipped_item(game_t *gm, play_t *game)
{
    int part = game->selectioned_item;

    unequip_item(gm, game, part);
    game->button->buttons[2]->can_draw = DROW_TOUCH;
    game->button->buttons[3]->can_draw = CONST;
}