/*
** EPITECH PROJECT, 2021
** player_stat
** File description:
** Player stat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include <stdlib.h>

player_stat_t *init_player_stat(save_t *save)
{
    player_stat_t *player = malloc(sizeof(player_stat_t));

    player->def = save->def;
    player->atck = save->atck;
    player->hp = save->hp;
    player->hp_max = save->hp_max;
    player->lvl = save->lvl;
    player->exp = save->exp;
    return player;
}