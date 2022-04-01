/*
** EPITECH PROJECT, 2021
** insert_mobs
** File description:
** Insert mobs
*/

#include "gamesys.h"
#include "./gameplay/mobs_struct.h"
#include "my.h"

static void insert_mobs_texture(mobs_t *mob, json_t *parser)
{
    if (my_strncmp(((json_t *)parser->data[0])->id, "texture", 7) == 0) {
        mob->texture =
        sfTexture_createFromFile(((json_t *)parser->data[0])->data[0], NULL);
    }
}

static void insert_mobs_sprite(mobs_t *mob)
{
    mob->stat.hp_max = mob->stat.hp;
    if (mob->texture) {
        mob->mobs = sfSprite_create();
        sfSprite_setTexture(mob->mobs, mob->texture, sfTrue);
        sfSprite_setTextureRect(mob->mobs, mob->rect);
    }
}

static void insert_mobs_stat(mobs_t *mob, json_t *parser)
{
    if (my_strncmp(((json_t *)parser->data[0])->id, "atck", 4) == 0) {
        mob->stat.atck = ((json_t *)parser->data[0])->data[0];
    }
    if (my_strncmp(((json_t *)parser->data[0])->id, "hp", 2) == 0) {
        mob->stat.hp = ((json_t *)parser->data[0])->data[0];
    }
    if (my_strncmp(((json_t *)parser->data[0])->id, "type", 4) == 0) {
        mob->type = ((json_t *)parser->data[0])->data[0];
    }
}

void insert_mobs(mobs_t *mob, json_t *parser)
{
    for (int j = 0; parser->data[j] != NULL; j++) {
        get_json_spritesheet(parser->data[j], &mob->rect);
        get_json_increment(parser->data[j], &mob->incre);
        get_json_increment_limit(parser->data[j], &mob->incre_limit);
        insert_mobs_texture(mob, parser->data[j]);
        insert_mobs_stat(mob, parser->data[j]);
    }
    insert_mobs_sprite(mob);
}