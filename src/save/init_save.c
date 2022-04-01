/*
** EPITECH PROJECT, 2021
** init_save
** File description:
** Init the save
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"
#include "my.h"
#include <stdlib.h>

static void init_save_inventory(json_t *parser, save_t *save)
{
    save->item_id = malloc(sizeof(int) * (NBR_ITEM + EQUIPPED_ITEM));
    for (int i = 0; parser->data[i]; ++i) {
        save->item_id[i] = ((json_t *)parser->data[i])->data[0];
    }
}

static void init_zero(save_t *save)
{
    save->atck = 5;
    save->def = 5;
    save->hp = 30;
    save->hp_max = 30;
    save->lvl = 1;
    save->exp = 0;
    save->win = 0;
    save->floor = 0;
    save->skill = 0;
}

save_t *init_save(char *filepath)
{
    json_t *parser = json_parser(filepath);
    save_t *save = malloc(sizeof(save_t));

    init_zero(save);
    for (int i = 0; parser->data[i] != NULL; ++i) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
            "save_inventory", 14) == 0)
            init_save_inventory(parser->data[i], save);
        json_int(parser->data[i], "lvl", 3, &save->lvl);
        json_int(parser->data[i], "atck", 4, &save->atck);
        json_int(parser->data[i], "hp", 2, &save->hp);
        json_int(parser->data[i], "max_hp", 6, &save->hp_max);
        json_int(parser->data[i], "def", 3, &save->def);
        json_int(parser->data[i], "win", 3, &save->win);
        json_int(parser->data[i], "floor", 5, &save->floor);
        json_int(parser->data[i], "exp", 3, &save->exp);
        json_int(parser->data[i], "skill", 5, &save->skill);
    }
    free_parser(parser);
    return save;
}