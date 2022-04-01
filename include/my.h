/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef _MY_H_
#define _MY_H_

typedef struct stroa
{
    int i;
    int ay;
    int lenx;
} sta;

void pt_array(char **mp);
char **str_to_arry_2(char *str, char ** arry, char a, sta *st);
char **str_to_array(char *str, char **arry, char a);
char *my_memset(char *str, int len);
int my_min(int x, int y);
int my_max(int x, int y);
char *my_itoa(int);
int sum(char **expr);
char *my_itoa(int nb);
int my_atoi(char *str);
int ba(char *a, char *b, int lena, int lenb);
void subba(char *a, char *b, int *c);
int sub(char *a, char *b, int *c);
void pint(int i, int *c, int k);
void add(char *a, char *b, int *c);
void extrem_min(void);
int    my_strlen(char const *);
char    *my_strncpy(char *, char const *, int);
int    my_strncmp(char const *, char const *, int);
void    my_swap(int *, int *);
char    *my_strupcase(char *);
char    *my_strncat(char *, char const *, int);
char    *my_strstr(char *, char *);
int    my_str_isupper(char const *);
int    my_str_isalpha(char const *);
int    my_str_isprintable(char const *);
char    *my_strlowcase(char *);
char    *my_strcat(char *, char const *);
char    *my_strdup(char const *);
int    my_str_isnum(char const *);
int    my_strcmp(char const *, char const *);
int    my_str_islower(char const *);
void    my_sort_int_array(int *, int);
char    *my_strcpy(char *, char const *);
char    *my_strcapitalize(char *);
int    my_showmem(char const *, int);
int    my_putstr(char *);
char    *my_revstr(char *);
int    my_showstr(char const *);
int    my_is_prime(int);
void    my_putchar(char);
int    my_isneg(int);
int    my_put_nbr(int);
int    my_compute_square_root(int);
int    my_getnbr(char *);
int    my_find_prime_sup(int);
int    my_compute_power_rec(int, int);
char    *concat_params(int, char **);
int    my_arraylen(char **);
int    my_charisnum(char const);
int    my_charisalpha(char const);
int count_words(char const *str);
int    word_len(char const *, int);
void init_buf(char buf[], int max);
#endif /* _MY_H_ */
