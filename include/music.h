/*
** EPITECH PROJECT, 2021
** music
** File description:
** music
*/

#ifndef MUSIC_H_
#define MUSIC_H_

#include <SFML/Audio.h>

typedef struct music_alone_s {
    sfMusic *music;
}music_alone_t;

typedef struct music_s {
    music_alone_t **sound_eff;
    music_alone_t **bg_music;
}music_t;

#endif /* !MUSIC_H_ */
