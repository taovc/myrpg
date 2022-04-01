/*
** EPITECH PROJECT, 2021
** check_mobs_dead
** File description:
** Check if mobs are dead
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void take_damage_mobs(game_t *gm, play_t *game, int target)
{
    update_hp_bar(game->combat->mobs[target]->hp_bar->hp,
        &game->combat->mobs[target]->stat.hp, (sfVector2f)
        {game->combat->mobs[target]->stat.hp_max, game->stats->atck});
    if (game->combat->mobs[target]->stat.hp <= 0) {
        kill_mobs(gm, game, target);
        if (check_dead(gm, game) == 1)
            return;
        get_new_target(game->combat);
    }
}
