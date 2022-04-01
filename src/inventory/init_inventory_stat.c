/*
** EPITECH PROJECT, 2021
** init_inventory_stat
** File description:
** Init inventory stat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "my.h"
#include <stdlib.h>

sfText *init_text(sfFont *font, char *str, int char_size, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, char_size);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    return text;
}

static void init_inv_text(buttons_t *button, player_stat_t *p_stat,
sfVector2f pos, inventory_stat_t *stat)
{
    pos.y = button->buttons[8]->pos.y + 20;
    stat->dmg = init_text(stat->font, my_itoa(p_stat->atck), 30, pos);
    pos.y = button->buttons[9]->pos.y + 20;
    stat->def = init_text(stat->font, my_itoa(p_stat->def), 30, pos);
    stat->lvl = init_text(stat->font, my_itoa(p_stat->lvl), 50, (sfVector2f)
    {button->buttons[16]->pos.x + 90, button->buttons[16]->pos.y + 10});
}

inventory_stat_t *init_inventory_stat(buttons_t *button,
player_stat_t *p_stat)
{
    inventory_stat_t *stat = malloc(sizeof(inventory_stat_t));
    sfVector2f pos = {button->buttons[7]->pos.x + 90,
    button->buttons[7]->pos.y + 20};
    int hp_len = my_strlen(my_itoa(p_stat->hp_max)) +
    my_strlen(my_itoa(p_stat->hp)) + 1;
    char *str = malloc(sizeof(char *) * (hp_len + 1));

    stat->font = sfFont_createFromFile("./imgs/Font.ttf");
    str[0] = '\0';
    str = my_strcat(str, my_itoa(p_stat->hp));
    str = my_strcat(str, " / ");
    str = my_strcat(str, my_itoa(p_stat->hp_max));
    stat->max_hp = init_text(stat->font, str, 30, pos);
    free(str);
    init_inv_text(button, p_stat, pos, stat);
    return stat;
}