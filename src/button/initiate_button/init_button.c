/*
** EPITECH PROJECT, 2021
** init_button
** File description:
** Init button
*/

#include "parser.h"
#include "./button/button_script.h"
#include "gamesys.h"
#include <stdlib.h>
#include "my.h"

static void init_button_zero(button_t *button)
{
    button->button = NULL;
    button->button_mouseover = NULL;
    button->button_text = NULL;
    button->script = 0;
    button->type = 0;
    button->mouseover = 0;
    button->can_draw = DROW_TOUCH;
    button->incre.x = 0;
    button->incre.y = 0;
    button->rect.left = 0;
    button->rect.top = 0;
    button->pos.x = 0;
    button->pos.y = 0;
}

static void init_button(json_t *parser, button_t **button)
{
    for (int i = 0, j = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
            "button", 6) == 0) {
            button[j] = malloc(sizeof(button_t));
            init_button_zero(button[j]);
            insert_button(parser->data[i], button[j]);
            j++;
        }
    }
}

buttons_t *init_struct_button(char *filepath)
{
    json_t *parser = json_parser(filepath);
    int len = get_json_args(parser, "button", 6);
    buttons_t *button = malloc(sizeof(buttons_t));

    button->buttons = malloc(sizeof(button_t *) * (len + 1));
    button->buttons[len] = NULL;
    button->type = menu;
    init_button(parser, button->buttons);
    free_parser(parser);
    free(parser->data);
    free(parser);
    return button;
}
