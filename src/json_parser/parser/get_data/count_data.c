/*
** EPITECH PROJECT, 2021
** count_data
** File description:
** Count the nbr of data we have
*/

#include "parser.h"
#include <stdio.h>

static int skip_open(char *str, int i)
{
    if (str[i] == '{')
        for (;str[i] && str[i] != '}'; i++);
    else if (str[i] == '[')
        for (;str[i] && str[i] != ']'; i++);
    return i;
}

int count_nbr_data(char *str, int i)
{
    int data = 1;
    char to_check = 0;

    if (str[i] == '{')
        to_check = '}';
    else if (str[i] == '[')
        to_check = ']';
    for (i++; str[i] && str[i] != to_check; i++) {
        i = skip_open(str, i);
        if (str[i] == ',')
            data++;
    }
    return data;
}