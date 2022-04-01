/*
** EPITECH PROJECT, 2020
** my_itoa.c
** File description:
** change_int_to_string
*/

#include <stdlib.h>

char *my_memset(char *str, int len)
{
    str = malloc(sizeof(char) * len);
    for (int i = 0; i <= len + 1; str[i] = '\0', i++);
    return str;
}