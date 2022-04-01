/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "gamesys.h"
#include "./button/button_script.h"
#include <stdlib.h>

void exit_game(game_t *gm)
{
    gm->now_parti = exit_parti;
}

game_t *create_gamesys(void)
{
    game_t *gm = malloc(sizeof(game_t));

    if (gm == NULL) {
        return NULL;
    }
    gm->time = malloc(sizeof(time_handle_t));
    start_timer(gm->time);
    gm->souri = create_text_sp("./imgs/souri.png", -9999, 0);
    gm->window = createmywindow(1400, 900);
    gm->now_parti = menu_parti;
    gm->get_parti = parti_now_used;
    gm->type = menu;
    gm->music_open = 1;
    gm->last_item = 0;
    gm->timer_spritesheet = one_sec;
    gm->snd_button = NULL;
    gm->snd_click = NULL;
    init_quest(gm);
    return gm;
}