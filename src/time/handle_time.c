/*
** EPITECH PROJECT, 2021
** handle_time
** File description:
** Handle the time
*/

#include "time.h"
#include <SFML/System.h>
#include <stdlib.h>

void start_timer(time_handle_t *time)
{
    time->clock = sfClock_create();
    time->delta_time = 0;
    time->fps = 0;
    time->previous_frame = 0;
}

void update_time(time_handle_t *time)
{
    sfUint64 elapsed_time = sfClock_getElapsedTime(time->clock).microseconds;

    time->delta_time = (float)(elapsed_time - time->previous_frame) / 1000000.0;
    time->fps = 1.f / time->delta_time;
    time->previous_frame = elapsed_time;
}

void end_timer(time_handle_t *time)
{
    if (time->clock != NULL) {
        sfClock_destroy(time->clock);
        free(time);
    }
}