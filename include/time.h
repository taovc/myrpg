/*
** EPITECH PROJECT, 2021
** time
** File description:
** Time
*/

#ifndef TIME_H_
#define TIME_H_

#include <SFML/Graphics.h>

typedef struct time_handle_s {
    sfClock *clock;
    size_t previous_frame;
    float delta_time;
    float fps;
}time_handle_t;

void start_timer(time_handle_t *time);
void update_time(time_handle_t *time);
void end_timer(time_handle_t *time);

#endif /* !TIME_H_ */