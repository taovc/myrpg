/*
** EPITECH PROJECT, 2021
** save_dungeon
** File description:
** Save the dungeon
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void save_dungeon_state(play_t *game, FILE *file)
{
    save_int(file, game->is_win, 1, "win");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->floor, 1, "floor");
}