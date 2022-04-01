/*
** EPITECH PROJECT, 2021
** save
** File description:
** Save the game
*/

#include "gamesys.h"
#include <stdlib.h>
#include "my.h"
#include "./inventory/item.h"
#include "./gameplay/gameplay.h"

static void put_tab(FILE *file, int tab)
{
    for (int i = 0; i < tab; ++i) {
        fwrite("    ", sizeof(char) * 4, 1, file);
    }
}

static void save_id(FILE *file, char *id, int tab)
{
    put_tab(file, tab);
    fwrite("\"", sizeof(char), 1, file);
    fwrite(id, sizeof(char) * my_strlen(id), 1, file);
    fwrite("\": ", sizeof(char) * 3, 1, file);
}

void save_arr(FILE *file, int *arr, int size, char *id)
{
    save_id(file, id, 2 - 1);
    fwrite("[\n", sizeof(char) * 2, 1, file);
    for (int i = 0; i < size; ++i) {
        put_tab(file, 2);
        fwrite(my_itoa(arr[i]), sizeof(char) *
        my_strlen(my_itoa(arr[i])), 1, file);
        if (i < size - 1)
            fwrite(",", sizeof(char), 1, file);
        fwrite("\n", sizeof(char), 1, file);
    }
    put_tab(file, 2 - 1);
    fwrite("]", sizeof(char) * 1, 1, file);
}

void save_int(FILE *file, int value, int tab, char *id)
{
    save_id(file, id, tab);
    fwrite(my_itoa(value), sizeof(char) * my_strlen(my_itoa(value)), 1, file);
}

void save_game(game_t *gm, play_t *game)
{
    FILE *file = fopen("save.json", "wb");
    int *arr = construct_arr_from_inventory(game);

    fwrite("{\n", sizeof(char) * 2, 1, file);
    save_stat(game, file);
    save_inventory(game, file);
    save_dungeon_state(game, file);
    fwrite("\n}", sizeof(char) * 2, 1, file);
    fclose(file);
    free(arr);
}
