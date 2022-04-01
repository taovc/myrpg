/*
** EPITECH PROJECT, 2021
** start_combat
** File description:
** Start a combat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

void start_combat(game_t *gm, play_t *game)
{
    init_combat(game, gm, game->map->tag);
    update_type(gm, in_combat);
}
