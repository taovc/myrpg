/*
** EPITECH PROJECT, 2021
** check_dead
** File description:
** Check if all monster are dead
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

int check_dead(game_t *gm, play_t *game)
{
    int dead = 0;

    for (int i = 0; game->combat->mobs[i]; ++i) {
        if (game->combat->mobs[i]->stat.hp <= 0)
            dead++;
    }
    if (dead == game->combat->nbr_mobs) {
        win(gm, game);
        return 1;
    }
    return 0;
}

void get_new_target(combat_t *combat)
{
    int i = 0;

    for (i = 0; combat->mobs[i] && combat->mobs[i]->stat.hp <= 0; ++i);
    combat->target_nbr = i;
    set_target_pos(combat);
}