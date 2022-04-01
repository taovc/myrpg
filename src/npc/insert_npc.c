/*
** EPITECH PROJECT, 2021
** insert_npc
** File description:
** Insert npc
*/

#include "gamesys.h"
#include "my.h"
#include "./gameplay/gameplay_struct.h"
#include <stdlib.h>

static void insert_npc_type(json_t *parser, npc_t *npc)
{
    if (my_strncmp(((json_t *)parser->data[0])->id, "npc_id", 6) == 0)
        npc->npc_id = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "zone", 4) == 0)
        npc->zone = ((json_t *)parser->data[0])->data[0];
}

static char *format_string_with_enter(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;

    for (int i = 0; str[i]; ++i, ++j) {
        if (str[i] == '\\' && str[i + 1] == 'n') {
            ++i;
            new_str[j] = '\n';
        } else
            new_str[j] = str[i];
    }
    new_str[j] = NULL;
    return new_str;
}

static void insert_npc_texture(json_t *parser, npc_t *npc)
{
    sfVector2f pos;
    char *str;

    if (my_strncmp(((json_t *)parser->data[0])->id, "texture", 7) == 0) {
        npc->texture =
        sfTexture_createFromFile(((json_t *)parser->data[0])->data[0], NULL);
    }
    if (my_strncmp(((json_t *)parser->data[0])->id, "dialog", 6) == 0) {
        npc->dialog = sfText_create();
        pos.x = npc->pos.x;
        pos.y = npc->pos.y + 50;
        npc->font = sfFont_createFromFile("./imgs/Font.ttf");
        sfText_setFillColor(npc->dialog, sfBlack);
        sfText_setFont(npc->dialog, npc->font);
        str = format_string_with_enter(((json_t *)parser->data[0])->data[0]);
        sfText_setString(npc->dialog, str);
        sfText_setPosition(npc->dialog, pos);
        free(str);
    }
}

static void insert_npc_sprite(npc_t *npc)
{
    if (npc->texture) {
        npc->sprite = sfSprite_create();
        sfSprite_setTexture(npc->sprite, npc->texture, sfTrue);
        sfSprite_setTextureRect(npc->sprite, npc->rect);
        sfSprite_setPosition(npc->sprite, npc->pos);
    }
}

void insert_npc(json_t *parser, npc_t *npc)
{
    for (int j = 0; parser->data[j] != NULL; j++) {
        get_json_spritesheet(parser->data[j], &npc->rect);
        get_json_pos(parser->data[j], &npc->pos);
        get_json_increment(parser->data[j], &npc->incre);
        get_json_increment_limit(parser->data[j], &npc->incre_limit);
        insert_npc_type(parser->data[j], npc);
        insert_npc_texture(parser->data[j], npc);
        insert_npc_sprite(npc);
    }
}