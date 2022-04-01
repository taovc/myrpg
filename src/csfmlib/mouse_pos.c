/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** mouse
*/

#include "gamesys.h"

void change_pos_souri(sfSprite *sp, sfRenderWindow *window)
{
    sfVector2f mouse;

    mouse.x = sfMouse_getPositionRenderWindow(window).x - 13;
    mouse.y = sfMouse_getPositionRenderWindow(window).y - 11;
    sfSprite_setPosition(sp, mouse);
}