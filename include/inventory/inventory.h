/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** Inventory header file
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <SFML/Graphics.h>
#include "./inventory/item_struct.h"
#include "./menu/menu_struct.h"

typedef struct inventory_s {
    int item_id;
    int type;
    sfSprite *sprite;
    sfTexture *texture;
}inventory_t;

typedef struct equipped_inventory_s {
    item_t *item;
    sfSprite *sprite;
    sfTexture *texture;
    int item_id;
}equipped_inventory_t;

typedef struct save_s {
    int hp;
    int hp_max;
    int lvl;
    int atck;
    int def;
    int *item_id;
    int win;
    int floor;
    int exp;
    int skill;
}save_t;

#endif /* !INVENTORY_H_ */
