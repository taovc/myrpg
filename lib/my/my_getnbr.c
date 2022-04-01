/*
** EPITECH PROJECT, 2020
** getnbr.c
** File description:
** to_getnbr_in_string
*/

#include "my.h"

int my_getnbr(char *str)
{
    int nb = 0, isneg = 1, i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - '0';
        i = i + 1;
        } else
            return (nb * isneg);
    }
    return (nb * isneg);
}