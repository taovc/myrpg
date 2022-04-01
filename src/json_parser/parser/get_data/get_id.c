/*
** EPITECH PROJECT, 2021
** get_id
** File description:
** Get the id of the object
*/

#include <stdio.h>
#include <stdlib.h>

char *get_id(char *str, int *i)
{
    const int stock_i = *i;
    int len = 0;
    char *new_str = NULL;

    for ((*i)++; str[*i] && str[*i] != '\"'; (*i)++, len++);
    *i = stock_i + 1;
    new_str = malloc(sizeof(char) * (len + 1));
    new_str[len] = '\0';
    for (int j = 0; str[*i] && str[*i] != '\"'; (*i)++, j++)
        new_str[j] = str[*i];
    return new_str;
}