/*
** EPITECH PROJECT, 2021
** count_json_args
** File description:
** Count the number of args in a json file
*/

#include "gamesys.h"
#include "my.h"

int get_json_args(json_t *ui_parser, char *compare, int str_len)
{
    int len = 0;

    for (int i = 0; ui_parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)ui_parser->data[i])->id,
            compare, str_len) == 0) {
            ++len;
        }
    }
    return len;
}
