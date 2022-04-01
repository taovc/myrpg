/*
** EPITECH PROJECT, 2021
** get_json_data
** File description:
** Get a json data
*/

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static void *get_string(char *str, int *i, char *id)
{
    const int stock_i = *i;
    int len = 0;
    char *new_str = NULL;
    json_t *parser = malloc(sizeof(json_t));

    for ((*i)++; str[*i] && str[*i] != '\"'; (*i)++, len++);
    *i = stock_i + 1;
    new_str = malloc(sizeof(char) * (len + 1));
    new_str[len] = '\0';
    for (int j = 0; str[*i] && str[*i] != '\"'; (*i)++, j++)
        new_str[j] = str[*i];
    parser->id = id;
    parser->type = string;
    parser->data = malloc(sizeof(void *) * 2);
    parser->data[0] = new_str;
    parser->data[1] = NULL;
    return parser;
}

static void *get_integer(char *str, int *i, char *id)
{
    int len = 0;
    const int stock_i = *i;
    char *new_str = NULL;
    json_t *parser = malloc(sizeof(json_t));

    for (; (str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-'; (*i)++, len++);
    *i = stock_i;
    new_str = malloc(sizeof(char) * (len + 1));
    new_str[len] = '\0';
    for (int j = 0; (str[*i] >= '0' && str[*i] <= '9')
    || str[*i] == '-'; (*i)++, j++)
        new_str[j] = str[*i];
    parser->id = id;
    parser->type = integer;
    parser->data = malloc(sizeof(void *) * 2);
    parser->data[0] = my_getnbr(new_str);
    parser->data[1] = NULL;
    free(new_str);
    return parser;
}


static void get_array(char *str, int *i, json_t *parser)
{
    int nbr_data = count_nbr_data(str, *i);
    parser->data = malloc(sizeof(json_t) * (nbr_data + 1));

    (*i)++;
    parser->data[nbr_data] = NULL;
    for (int type = -1, incre = 0; str[*i] && str[*i] != ']'
    && incre < nbr_data; (*i)++, incre++) {
        for (; str[*i] == ' ' || str[*i] == '\n'; (*i)++);
        type = check_type(str, *i);
        if (type == integer)
            parser->data[incre] = get_integer(str, i, NULL);
        else if (type == string) {
            parser->data[incre] = get_string(str, i, NULL);
            (*i)++;
        }
        ((json_t *)parser->data[incre])->id = NULL;
        ((json_t *)parser->data[incre])->type = type;
    }
}

static void get_object(char *str, int *i, int nbr_data, json_t *parser)
{
    parser_loop(parser, str, i, nbr_data);
}

void *get_value(char *str, int *i, int type, char *id)
{
    json_t *parser = NULL;

    parser = malloc(sizeof(json_t));
    parser->id = id;
    parser->type = type;
    if (type == string) {
        parser->data = malloc(sizeof(json_t) * 2);
        parser->data[0] = get_string(str, i, id);
        parser->data[1] = NULL;
    }
    if (type == integer) {
        parser->data = malloc(sizeof(json_t) * 2);
        parser->data[0] = get_integer(str, i, id);
        parser->data[1] = NULL;
    }
    if (type == array)
        get_array(str, i, parser);
    if (type == object)
        get_object(str, i, count_nbr_data(str, *i), parser);
    return parser;
}