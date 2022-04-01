/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** putstr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
