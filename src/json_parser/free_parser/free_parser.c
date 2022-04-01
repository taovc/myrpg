/*
** EPITECH PROJECT, 2021
** free_parser
** File description:
** Free parser
*/

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

static void free_parser_arr(json_t *parser, int i)
{
    for (int j = 0, type = -1;
    ((json_t *)parser->data[i])->data[j] != NULL; j++) {
        type = ((json_t *)((json_t *)parser->data[i])->data[j])->type;
        if (type == string)
            free(((json_t *)((json_t *)parser->data[i])->data[j])->data[0]);
        free(((json_t *)((json_t *)parser->data[i])->data[j])->data);
        free(((json_t *)parser->data[i])->data[j]);
    }
}

void free_parser(json_t *parser)
{
    for (int i = 0, type = -1; parser->data[i]; i++) {
        type = ((json_t *)parser->data[i])->type;
        if (type == object)
            free_parser((json_t *)parser->data[i]);
        if (type == array)
            free_parser_arr(parser, i);
        if (type == string)
            free(((json_t *)((json_t *)parser->data[i])->data[0])->data[0]);
        if (type == string || type == integer) {
            free(((json_t *)((json_t *)parser->data[i])->data[0])->data);
            free(((json_t *)parser->data[i])->data[0]);
        }
        free(((json_t *)parser->data[i])->id);
        free(((json_t *)parser->data[i])->data);
        free(parser->data[i]);
    }
}
