/*
** EPITECH PROJECT, 2021
** save_stat
** File description:
** Save player stat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void save_stat(play_t *game, FILE *file)
{
    save_int(file, game->stats->lvl, 1, "lvl");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->stats->exp, 1, "exp");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->stats->atck, 1, "atck");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->stats->hp, 1, "hp");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->stats->hp_max, 1, "max_hp");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->stats->def, 1, "def");
    fwrite(",\n", sizeof(char) * 2, 1, file);
    save_int(file, game->skill_type, 1, "skill");
    fwrite(",\n", sizeof(char) * 2, 1, file);
}