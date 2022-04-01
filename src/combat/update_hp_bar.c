/*
** EPITECH PROJECT, 2021
** update_hp_bar
** File description:
** Update the hp bar
*/

#include "gamesys.h"

void update_hp_bar(sfSprite *hp_bar, int *hp, sfVector2f hp_took)
{
    int width = 0;

    sfSprite_setTextureRect(hp_bar, (sfIntRect){0, 0, 166, 25});
    *hp -= hp_took.y;
    if (*hp > hp_took.x)
        *hp = hp_took.x;
    width = (166 / hp_took.x) * (*hp);
    if (width > 166)
        width = 166;
    sfSprite_setTextureRect(hp_bar, (sfIntRect){0, 0, width, 25});
}