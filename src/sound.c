/*
** EPITECH PROJECT, 2021
** sound.c
** File description:
** my_rpg
*/

#include "../include/menu/menu_struct.h"
#include "./gameplay/gameplay.h"
#include "./music.h"

sfMusic *play_music(char *str)
{
    sfMusic *sound_menu = sfMusic_createFromFile(str);

    sfMusic_setLoop(sound_menu, sfTrue);
    sfMusic_play(sound_menu);
    return sound_menu;
}

sfMusic *music_click(void)
{
    sfMusic *snd_click = sfMusic_createFromFile("./sound/click_button.ogg");

    sfMusic_play(snd_click);
    return snd_click;
}

sfMusic *music_button(void)
{
    sfMusic *snd_button = sfMusic_createFromFile("./sound/epe_effect.ogg");

    sfMusic_play(snd_button);
    return snd_button;
}