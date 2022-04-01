/*
** EPITECH PROJECT, 2021
** init_mobs
** File description:
** Init mobs array
*/

#include "gamesys.h"
#include "./gameplay/mobs_struct.h"
#include "./gameplay/gameplay.h"
#include "my.h"
#include <stdlib.h>

static void insert_mobs_zero(mobs_t *mob)
{
    mob->mobs = NULL;
    mob->texture = NULL;
    mob->incre.x = 0;
    mob->incre.y = 0;
    mob->incre_limit.x = 0;
    mob->incre_limit.y = 0;
    mob->rect.height = 0;
    mob->rect.left = 0;
    mob->rect.top = 0;
    mob->rect.width = 0;
    mob->stat.atck = 1;
    mob->stat.hp = 1;
    mob->stat.hp_max = 1;
    mob->type = 0;
}

mob_list_t *init_mobs(char *filepath)
{
    json_t *parser = json_parser(filepath);
    int nbr_args = get_json_args(parser, "mob", 3);
    mob_list_t *mobs = malloc(sizeof(mob_list_t));

    mobs->nbr_mobs = nbr_args;
    mobs->mobs_list = malloc(sizeof(mobs_t *) * (nbr_args + 1));
    mobs->mobs_list[nbr_args] = NULL;
    for (int i = 0, j = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "mob", 3) == 0) {
            mobs->mobs_list[j] = malloc(sizeof(mobs_t));
            insert_mobs_zero(mobs->mobs_list[j]);
            insert_mobs(mobs->mobs_list[j], parser->data[i]);
            j++;
        }
    }
    return mobs;
}