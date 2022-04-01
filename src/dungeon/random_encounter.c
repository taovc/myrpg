/*
** EPITECH PROJECT, 2021
** random_encounter
** File description:
** Random encounter
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include <stdlib.h>

void random_encounter(game_t *gm, play_t *py)
{
    int proc = 0;

    if (py->floor == 0)
        return;
    srand(sfClock_getElapsedTime(gm->time->clock).microseconds);
    proc = rand() % 500;
    if (proc == 1)
        start_combat(gm, py);
}