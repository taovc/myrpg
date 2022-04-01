/*
** EPITECH PROJECT, 2021
** insert_items
** File description:
** Insert items
*/

#include "gamesys.h"
#include "./inventory/item.h"
#include "gameplay/gameplay_struct.h"

void insert_equip_item(equipped_inventory_t *inventory, int item_id,
int item, buttons_t *button)
{
    sfVector2f pos = {0, 0};

    pos.y = ((item / 2) * 85) + (button->buttons[2]->pos.y + 98);
    pos.x = ((item - ((item / 2) * 2)) * 80) + (button->buttons[2]->pos.x + 69);
    inventory->item->attack = item_arr[item_id].attack;
    inventory->item->hp = item_arr[item_id].hp;
    inventory->item->type = item_arr[item_id].type;
    inventory->item_id = item_id;
    inventory->texture =
    sfTexture_createFromFile(item_arr[item_id].texture, NULL);
    inventory->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfFalse);
    sfSprite_setPosition(inventory->sprite, pos);
}

void insert_item(inventory_t *inventory, int item_id, int item,
buttons_t *button)
{
    sfVector2f pos = {0, 0};

    pos.y = (item / 9) * Item_y + button->buttons[0]->pos.y;
    pos.x = (item - ((item / 9) * 9)) * Item_x + button->buttons[0]->pos.x;
    inventory->item_id = item_id;
    inventory->type = item_arr[item_id].type;
    inventory->texture =
    sfTexture_createFromFile(item_arr[item_id].texture, NULL);
    inventory->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->sprite, inventory->texture, sfFalse);
    sfSprite_setPosition(inventory->sprite, pos);
}