/*
** EPITECH PROJECT, 2021
** item
** File description:
** Item header file
*/

#ifndef ITEM_H_
#define ITEM_H_

#include <SFML/Graphics.h>
#include "./inventory/item_struct.h"

enum item_type {
    nothing,
    sword,
    usable,
    helmet,
    chest,
    legs,
    shoes
};

static int const NBR_ITEM = 54;
static int const Item_x = 77;
static int const Item_y = 79;
static int const EQUIPPED_ITEM = 4;

static int const armor = 7;
static int const weapon = 4;
static int const potion = 1;

static const item_t item_arr[] = {
    {"./imgs/Empty.png", 0, 0, 0, nothing},
    {"./imgs/inventory_assets/potion_low.png", 0, 10, 0, usable},
    {"./imgs/inventory_assets/potion_medium.png", 0, 15, 0, usable},
    {"./imgs/inventory_assets/potion_up.png", 0, 20, 0, usable},
    {"./imgs/inventory_assets/sword_low.png", 8, 0, 0, sword},
    {"./imgs/inventory_assets/sword_medium.png", 10, 0, 0, sword},
    {"./imgs/inventory_assets/sword_up.png", 15, 0, 0, sword},
    {"./imgs/inventory_assets/armor_low.png", 0, 0, 2, chest},
    {"./imgs/inventory_assets/armor_medium.png", 0, 0, 5, chest},
    {"./imgs/inventory_assets/armor_up.png", 0, 0, 8, chest}
};

#endif /* !ITEM_H_ */