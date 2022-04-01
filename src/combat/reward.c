/*
** EPITECH PROJECT, 2021
** reward
** File description:
** Reward
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"
#include <stdlib.h>

static void low_reward(game_t *gm, play_t *game)
{
    int item = 0;

    srand(sfClock_getElapsedTime(gm->time->clock).microseconds);
    item = rand() % 100;
    if (item >= 0 && item <= 70)
        item = potion + 1;
    else {
        if (rand() % 2 == 1)
            item = armor;
        else
            item = weapon;
    }
    give_item(gm, game, item);
}

static void medium_reward(game_t *gm, play_t *game)
{
    int item = 0;
    int which = -1;

    srand(sfClock_getElapsedTime(gm->time->clock).microseconds);
    item = rand() % 100;
    if (item >= 0 && item <= 60)
        item = potion + 1;
    else if (item > 60 && item <= 89)
        which = 0;
    else
        which = 1;
    if (which != -1) {
        if (rand() % 2 == 1)
            item = armor + which;
        else
            item = weapon + which;
    }
    give_item(gm, game, item);
}

static void up_reward(game_t *gm, play_t *game)
{
    int item = 0;
    int which = 0;

    srand(sfClock_getElapsedTime(gm->time->clock).microseconds);
    item = rand() % 100;
    if (item >= 0 && item <= 60)
        item = potion + 2;
    else if (item > 60 && item <= 89)
        which = 1;
    else
        which = 2;
    if (which != 0) {
        if (rand() % 2 == 1)
            item = armor + which;
        else
            item = weapon + which;
    }
    give_item(gm, game, item);
}

void reward(game_t *gm, play_t *game)
{
    if (game->map->tag >= 1 && game->map->tag <= 2)
        low_reward(gm, game);
    else if (game->map->tag == 4)
        up_reward(gm, game);
    else
        medium_reward(gm, game);
}