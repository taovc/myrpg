/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return (0);
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
