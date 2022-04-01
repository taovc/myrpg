/*
** EPITECH PROJECT, 2021
** map
** File description:
** dungeon_map
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "gamesys.h"
#include "./gameplay/gameplay.h"

static char *read_file_map(char *str)
{
    int fd, len;
    struct stat buf;
    char *buff;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return NULL;
    stat(str, &buf);
    buff = malloc(sizeof(char) * buf.st_size);
    len = read(fd, buff, buf.st_size);
    if (len <= 0)
        return NULL;
    return buff;
}

static char **craet_map_txt(char *str)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * 25);
    for (int i = 0; i < 25; ++i)
        map[i] = NULL;
    for (int i = 0; i < 24; i++) {
        map[i] = malloc(sizeof(char) * 42);
        for (int x = 0; x < 42; ++x)
            map[i][x] = '\0';
        for (int j = 0; j < 41; j++)
            map[i][j] = str[j + i * 41];
    }
    return map;
}

static void init_lave_rect(game_t *gm, play_t *py)
{
    py->lave = create_text_sp("./imgs/dungeon/lava.png", 0, 0);
    py->water = create_text_sp("./imgs/dungeon/water.png", 0, 0);
    py->tp = create_text_sp("./imgs/dungeon/tp_is_ok.png", 0, 0);
    py->poison = create_text_sp("./imgs/dungeon/poison.png", 0, 0);
    py->my_map = create_text_sp("./imgs/gameplay/main_map.png", -960, -220);
    gm->timer_spritesheet = 0.5;
    py->lave_rect.height = 900;
    py->lave_rect.left = 0;
    py->lave_rect.top = 0;
    py->lave_rect.width = 1400;
    py->map_txt = craet_map_txt(read_file_map("./map/main_map.txt"));
    py->py_x = 21;
    py->py_y = 8;
}

void init_game_dungeon(play_t *game, game_t *gm)
{
    game->person = create_text_sp("./imgs/gameplay/person.png", 650, 360);
    game->person_rt.height = 120;
    game->person_rt.left = 0;
    game->person_rt.top = 370;
    game->person_rt.width = 90;
    sfSprite_setTextureRect(game->person, game->person_rt);
    game->map = init_djmaps("./config_files/gameplay/dj_map.json");
    game->head_map = game->map;
    init_lave_rect(gm, game);
}