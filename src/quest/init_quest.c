/*
** EPITECH PROJECT, 2021
** init_quest
** File description:
** Init quest
*/

#include "gamesys.h"
#include <stdlib.h>

void init_quest(game_t *gm)
{
    json_t *quest_parser = json_parser("./config_files/quest.json");

    free_parser(quest_parser);
    free(quest_parser->data);
    free(quest_parser);
}