/*
** EPITECH PROJECT, 2020
** my_atoi.tao.weijie
** File description:
** str->int
*/

#include "my.h"

void init_buf(char buf[], int max)
{
    for (int i = 0; i < max; buf[i] = '\0', i++);
}