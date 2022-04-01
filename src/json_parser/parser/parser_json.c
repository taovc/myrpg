/*
** EPITECH PROJECT, 2021
** parser_json
** File description:
** Parse a json file
*/

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

void skip_to_type(char *str, int *i)
{
    for (; str[*i] && str[*i] != ':'; (*i)++);
    if (str[*i] == ':')
        (*i)++;
    for (; str[*i] && str[*i] == ' '; (*i)++);
}

static int skip_to_id(char *str, int *i)
{
    for (; str[*i] && str[*i] != '\"'; (*i)++);
    if (str[*i] == '\0' || str[*i] == '}')
        return 1;
    return 0;
}

void parser_loop(json_t *parser, char *str, int *i, int nbr_data)
{
    char *id = NULL;

    parser->data = malloc(sizeof(void *) * (nbr_data + 1));
    parser->data[nbr_data] = NULL;
    for (int type = 0, incre = 0; str[*i] && str[*i] != '}'
        && incre < nbr_data; (*i)++, incre++) {
        if (skip_to_id(str, i) == 1)
            break;
        id = get_id(str, i);
        skip_to_type(str, i);
        type = check_type(str, *i);
        parser->data[incre] = get_value(str, i, type, id);
    }
    if (!id)
        free(id);
}

json_t *json_parser(char *filepath)
{
    char *str = read_file(filepath);
    json_t *parser = malloc(sizeof(json_t));
    int i = 0;

    parser->id = NULL;
    parser->type = object;
    if (str == NULL || parser == NULL)
        return NULL;
    parser_loop(parser, str, &i, count_nbr_data(str, 0));
    free(str);
    return parser;
}
