/*
** EPITECH PROJECT, 2021
** update_type
** File description:
** Update the type
*/

#include "gamesys.h"

void update_type(game_t *gm, int new_type)
{
    gm->last_type = gm->type;
    gm->type = new_type;
}
