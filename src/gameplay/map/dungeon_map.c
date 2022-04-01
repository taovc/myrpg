/*
** EPITECH PROJECT, 2021
** map
** File description:
** dungeon_map
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "my.h"
#include <stdlib.h>

map_t *creat_mp_node(void)
{
    map_t *mp = malloc(sizeof(map_t));

    mp->leave = 0;
    mp->tag = 0;
    mp->map = NULL;
    mp->next = NULL;
    return mp;
}

map_t *insert_mp_node(map_t *head, map_t *data)
{
    head->next = data;
    return data;
}

static void insert_djmaps(json_t *parser, map_t *mp)
{
    for (int j = 0; parser->data[j] != NULL; j++) {
        if (my_strncmp(((json_t *)parser->data[j])->id, "tag", 3) == 0) {
            mp->tag = ((json_t *)
            ((json_t *)parser->data[j])->data[0])->data[0];
        }
        if (my_strncmp(((json_t *)parser->data[j])->id, "path", 4) == 0) {
            mp->map = create_text_sp(((json_t *)
            ((json_t *)parser->data[j])->data[0])->data[0], 0, 0);
        }
    }
}

map_t *init_djmaps(char *filepath)
{
    json_t *parser = json_parser(filepath);
    map_t *mphead = creat_mp_node();
    map_t *cphead = mphead;

    for (int i = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
        "map", 3) == 0) {
            insert_djmaps(parser->data[i], mphead);
            if (parser->data[i + 1] == NULL)
                break;
            mphead = insert_mp_node(mphead, creat_mp_node());
        }
    }
    return cphead;
}