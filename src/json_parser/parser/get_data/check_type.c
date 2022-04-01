/*
** EPITECH PROJECT, 2021
** check_type
** File description:
** Check the type of the data sended
*/

#include "parser.h"
#include <stdio.h>

int check_type(char *str, int i)
{
    int type = -1;

    for (; str[i] && str[i] == ' '; i++);
    switch (str[i]) {
        case '{':
            type = object;
            break;
        case '[':
            type = array;
            break;
        case '\"':
            type = string;
            break;
    }
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
        type = integer;
    return type;
}