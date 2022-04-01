/*
** EPITECH PROJECT, 2021
** interact_inventory
** File description:
** Interact with the inventory
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "./gameplay/gameplay_struct.h"
#include <stdio.h>

static void pop_interact_ui(play_t *game, int item, sfVector2f pos)
{
    if (game->inventories->inventory[item]->type == nothing)
        return;
    game->button->buttons[0]->can_draw = NOT;
    game->button->buttons[1]->can_draw = TOUCH;
    if (game->inventories->inventory[item]->type == usable) {
        game->button->buttons[1]->rect.left = 0;
    }
    else {
        game->button->buttons[1]->rect.left =
            game->button->buttons[1]->incre.x;
    }
    sfSprite_setTextureRect(game->button->buttons[1]->button,
        game->button->buttons[1]->rect);
    game->button->buttons[1]->pos.x = pos.x;
    game->button->buttons[1]->pos.y = pos.y;
    sfSprite_setPosition(game->button->buttons[1]->button, pos);
}

void interact_inventory(game_t *gm, play_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gm->window);
    sfVector2f pos = {mouse_pos.x, mouse_pos.y};
    int item = (mouse_pos.x - (int)game->button->buttons[0]->pos.x) / Item_x
        + ((mouse_pos.y - (int)game->button->buttons[0]->pos.y) / Item_y) * 9;

    game->selectioned_item = item;
    pop_interact_ui(game, item, pos);
}
