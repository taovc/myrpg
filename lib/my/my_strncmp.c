/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** strncmps
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return -1;
    return 0;
}
