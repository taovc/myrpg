/*
** EPITECH PROJECT, 2020
** my_atoi.tao.weijie
** File description:
** str->int
*/

#include "my.h"

int my_atoi(char *str)
{
    int	res = 0, sign = 0, i = 0;

    ((str[i] == '-') ? (sign = 1, i++) : (0));
    if (str[0] == '+')
        i++;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += str[i] - '0';
        } else
            return (res);
        i++;
    }
    return ((sign == 0) ? (res) : (-res));
}