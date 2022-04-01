/*
** EPITECH PROJECT, 2021
** conditionnal_draw
** File description:
** Draw on condition
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void game_conditional_draw(game_t *gm, play_t *game)
{
    draw_inventories(gm, game);
    draw_combat(gm, game->combat);
}