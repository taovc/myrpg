/*
** EPITECH PROJECT, 2021
** player_equiped_item
** File description:
** Deal with the equipped items of the player
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include <stdio.h>
#include "./gameplay/gameplay_struct.h"

static void pop_interact_equip_ui(play_t *game, int item, sfVector2f pos)
{
    if (game->inventories->equip_inventory[item]->item->type == nothing)
        return;
    game->button->buttons[2]->can_draw = NOT;
    game->button->buttons[3]->can_draw = TOUCH;
    game->button->buttons[3]->pos.x = pos.x;
    game->button->buttons[3]->pos.y = pos.y;
    sfSprite_setPosition(game->button->buttons[3]->button, pos);
}

void detect_body_part(game_t *gm, play_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gm->window);
    sfVector2f pos = {mouse_pos.x, mouse_pos.y};
    int column = ((mouse_pos.y - (game->button->buttons[2]->pos.y + 98)) / 85);
    int part =  ((mouse_pos.x - (game->button->buttons[2]->pos.x + 69)) / 80)
    + column * 2;

    game->selectioned_item = part;
    if (mouse_pos.x > game->button->buttons[2]->pos.x + 69
    && mouse_pos.x < game->button->buttons[2]->pos.x + 220 &&
    mouse_pos.y > game->button->buttons[2]->pos.y + 98 &&
    mouse_pos.y < game->button->buttons[2]->pos.y + 269)
        pop_interact_equip_ui(game, part, pos);
}