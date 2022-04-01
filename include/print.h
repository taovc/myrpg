/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef PRINT_H_
#define PRINT_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define octal "01234567"
#define bin "01"
#define hexa "0123456789ABCDEF"
#define ab "0123456789abcdef"

typedef struct flag
{
    char c;
    void(*fc)(va_list);
} flags;

void condition(int, va_list, char *);
void pint_sp(char *, int, va_list);
void my_printf(char *, ...);
void check_str(va_list, int, char *);
void my_putchar_2(va_list);
void my_putstr_2(va_list);
void my_put_nbr_bin_2(va_list);
void my_put_nbr_2(va_list);
void my_put_nbr_hexa(unsigned int);
void my_put_nbr_hexa_l(unsigned int);
void my_put_nbr_hexa_2(va_list);
void my_put_nbr_hexa_3(va_list);
void my_putstr_bis_2(va_list);
void my_put_nbr_octal_2(va_list);
void my_put_bis(char *);
void my_put_bis_2(va_list);
void my_put_nbr_octal(unsigned int);
void my_put_ad_2(va_list);
int my_put_nbr_bin(unsigned int);
void my_put_nbr_3(va_list ap);
int my_put_nbr_4(unsigned int);

#endif /* _!PRINT_H_ */