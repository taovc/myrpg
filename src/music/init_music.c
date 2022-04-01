/*
** EPITECH PROJECT, 2021
** init_music
** File description:
** Init music
*/

#include "gamesys.h"
#include "./gameplay/gameplay_struct.h"
#include "my.h"
#include <stdlib.h>

sfMusic *insert_music(json_t *parser)
{
    sfMusic *music;

    for (int i = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "sound", 5) == 0)
            music = sfMusic_createFromFile(((json_t *)
                ((json_t *)parser->data[i])->data[0])->data[0]);
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "repeat", 6) == 0)
            sfMusic_setLoop(music, sfTrue);
    }
    return music;
}

music_alone_t **init_music(char *filepath)
{
    json_t *parser = json_parser(filepath);
    int len = get_json_args(parser, "sound", 5);
    music_alone_t **music = malloc(sizeof(music_alone_t *) * (len + 1));

    for (int i = 0, j = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "sound", 5) == 0) {
            music[j] = malloc(sizeof(music_alone_t));
            music[j]->music = insert_music(parser->data[i]);
            j++;
        }
    }
    music[len] = NULL;
    return music;
}

music_t *init_combat_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->sound_eff =
    init_music("./config_files/gameplay/game_sound_effect.json");
    music->bg_music = NULL;
    return music;
}