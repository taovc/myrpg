/*
** EPITECH PROJECT, 2021
** mylib.c
** File description:
** lib_for_sfml
*/

#include "gamesys.h"

void evnt_switch(sfEvent evnt, game_t *gm)
{
    switch (evnt.type) {
    case sfEvtClosed:
        gm->now_parti = exit_parti;
        sfRenderWindow_close(gm->window);
        break;
    default:
        break;
    }
}

void (*parti_now_used(unsigned short id))
{
    int i = 0;

    for (i = 0; i < NB_parti; i++)
        if (ALL_parti[i].id == id)
            return ALL_parti[i].fc;
    return NULL;
}

sfRenderWindow *createmywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window  = sfRenderWindow_create(video_mode,
        "my.rpg", sfDefaultStyle, NULL);
    return (window);
}