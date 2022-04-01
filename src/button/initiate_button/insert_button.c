/*
** EPITECH PROJECT, 2021
** init_button
** File description:
** Initiate all the buttons
*/

#include "my.h"
#include "parser.h"
#include "./button/button_script.h"
#include "gamesys.h"

static void insert_button_script(json_t *button_parser,
button_t *button, int j)
{
    if (my_strncmp(((json_t *)button_parser->data[j])->id, "type", 4) == 0) {
        button->type = ((json_t *)
            ((json_t *)button_parser->data[j])->data[0])->data[0];
    }
    if (my_strncmp(((json_t *)button_parser->data[j])->id, "script", 6) == 0)
    {
        button->script = ((json_t *)
            ((json_t *)button_parser->data[j])->data[0])->data[0];
    }
}

static void insert_button_texture(json_t *button_parser,
button_t *button, int j)
{
    if (my_strncmp(((json_t *)button_parser->data[j])->id,
        "texture", 7) == 0)
        button->button_text = sfTexture_createFromFile(
            ((json_t *)((json_t *)button_parser->data[j])->data[0])->data[0],
            NULL);
    if (my_strncmp(((json_t *)button_parser->data[j])->id,
        "mouseover", 9) == 0)
        button->button_mouseover = sfTexture_createFromFile(
            ((json_t *)((json_t *)button_parser->data[j])->data[0])->data[0],
            NULL);
}

static void insert_button_sprite(button_t *button)
{
    if (button->button_text != NULL) {
        button->button = sfSprite_create();
        sfSprite_setTexture(button->button, button->button_text, sfTrue);
        sfSprite_setPosition(button->button, button->pos);
        sfSprite_setTextureRect(button->button, button->rect);
    }
}

void insert_button(json_t *button_parser, button_t *button)
{
    for (int j = 0; button_parser->data[j] != NULL; j++) {
        insert_button_script(button_parser, button, j);
        get_json_pos(button_parser->data[j], &button->pos);
        get_json_spritesheet(button_parser->data[j], &button->rect);
        get_json_increment(button_parser->data[j], &button->incre);
        if (my_strncmp(((json_t *)button_parser->data[j])->id, "can", 3) == 0)
            button->can_draw = ((json_t *)
                ((json_t *)button_parser->data[j])->data[0])->data[0];
        insert_button_texture(button_parser, button, j);
    }
    insert_button_sprite(button);
}
