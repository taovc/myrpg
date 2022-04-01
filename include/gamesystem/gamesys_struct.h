/*
** EPITECH PROJECT, 2021
** gamesys_struct.h
** File description:
** Game system structure
*/

#ifndef GAMESYS_STRUCT_H_
#define GAMESYS_STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include "./button/button.h"
#include "time.h"
#include "ui.h"

enum can_we_draw{
    DROW_TOUCH,
    TOUCH,
    CONST,
    NOT
};

typedef struct gamesys_e {
    void *(*get_parti)(unsigned short id);
    sfRenderWindow *window;
    sfSprite *souri;
    time_handle_t *time;
    sfEvent event;
    unsigned short now_parti;
    int type;
    int music_open;
    int zone;
    int last_item;
    int last_type;
    float timer_spritesheet;
    sfMusic *snd_click;
    sfMusic *snd_button;
} game_t;

#endif /* !GAMESYS_STRUCT_H_ */
