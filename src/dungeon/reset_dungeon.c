/*
** EPITECH PROJECT, 2021
** reset_dungeon
** File description:
** Reset the dungeon
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void reset_dungeon(game_t *gm, play_t *game)
{
    game->floor = 0;
}