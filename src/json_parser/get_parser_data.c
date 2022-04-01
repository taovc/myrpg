/*
** EPITECH PROJECT, 2021
** get_parser_data
** File description:
** Get data from the parser
*/

#include "gamesys.h"
#include "my.h"

void json_int(json_t *parser, char *cmp, int len, int *value)
{
    if (my_strncmp(parser->id, cmp, len) == 0) {
        *value = ((json_t *)parser->data[0])->data[0];
    }
}