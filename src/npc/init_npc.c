/*
** EPITECH PROJECT, 2021
** Init npc
** File description:
** Init the npcs
*/

#include "gamesys.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include "./gameplay/gameplay.h"

static void insert_npc_zero(npc_t *npc)
{
    npc->texture = NULL;
    npc->dialog = NULL;
    npc->sprite = NULL;
    npc->npc_id = random_npc;
    npc->zone = village;
    npc->pos.x = 0;
    npc->pos.y = 0;
    npc->rect.height = 0;
    npc->rect.left = 0;
    npc->rect.top = 0;
    npc->rect.width = 0;
    npc->incre.x = 0;
    npc->incre.y = 0;
    npc->incre_limit.x = 0;
    npc->incre_limit.y = 0;
}

npc_t **init_npc(char *filepath)
{
    json_t *parser = json_parser(filepath);
    int nbr_args = get_json_args(parser, "npc", 3);
    npc_t **npc = malloc(sizeof(npc_t *) * (nbr_args + 1));

    npc[nbr_args] = NULL;
    for (int i = 0, j = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "npc", 3) == 0) {
            npc[j] = malloc(sizeof(npc_t));
            insert_npc_zero(npc[j]);
            insert_npc(parser->data[i], npc[j]);
            j++;
        }
    }
    return npc;
}