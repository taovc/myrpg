/*
** EPITECH PROJECT, 2021
** free_music
** File description:
** Free music
*/

#include "gamesys.h"
#include "./gameplay/gameplay_struct.h"
#include <stdlib.h>

void free_music(music_alone_t **music)
{
    for (int i = 0; music[i]; ++i) {
        sfMusic_destroy(music[i]->music);
        free(music[i]);
    }
    free(music);
}