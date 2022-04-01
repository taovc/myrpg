/*
** EPITECH PROJECT, 2021
** update_inventory_stat
** File description:
** Update the inventory stat
*/

#include "./gameplay/gameplay.h"
#include "my.h"
#include <stdlib.h>

void update_inv_stat(inventory_stat_t *stat, player_stat_t *p_stat)
{
    int hp_len = my_strlen(my_itoa(p_stat->hp_max)) +
    my_strlen(my_itoa(p_stat->hp)) + 1;
    char *str = malloc(sizeof(char *) * (hp_len + 1));

    stat->font = sfFont_createFromFile("./imgs/Font.ttf");
    str[0] = '\0';
    str = my_strcat(str, my_itoa(p_stat->hp));
    str = my_strcat(str, " / ");
    str = my_strcat(str, my_itoa(p_stat->hp_max));
    sfText_setString(stat->max_hp, str);
    sfText_setString(stat->dmg, my_itoa(p_stat->atck));
    sfText_setString(stat->def, my_itoa(p_stat->def));
    sfText_setString(stat->lvl, my_itoa(p_stat->lvl));
    free(str);
}