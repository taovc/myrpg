/*
** EPITECH PROJECT, 2021
** close_inventory
** File description:
** Close the inventory
*/

#include "gamesys.h"
#include "./button/button_script.h"

void close_inventory(game_t *gm)
{
    update_type(gm, gm->last_type);
}