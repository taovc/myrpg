/*
** EPITECH PROJECT, 2020
** concat_params.c
** File description:
** add\n_whith_word_return_string
*/

#include "my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    char *dest;
    int dest_size = 0;
    int i = 0;

    while (i < argc) {
        dest_size = dest_size + my_strlen(argv[i]) + 1;
        i++;
    }
    dest = malloc(sizeof(char) * dest_size + 1);
    i = 0;
    while (i < argc) {
        my_strcat(my_strcat(dest, argv[i]), "\n");
        i++;
    }
    my_strcat(dest, "\0");
    return (dest);
}
