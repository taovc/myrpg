/*
** EPITECH PROJECT, 2021
** draw_button
** File description:
** Draw the button
*/

#include "gamesys.h"
#include "./button/button_script.h"

void draw_buttons(game_t *gm, buttons_t *button)
{
    for (int i = 0; button->buttons[i]; ++i)
        if (button->buttons[i]->type == gm->type &&
            (button->buttons[i]->can_draw == TOUCH ||
            button->buttons[i]->can_draw == DROW_TOUCH ||
            button->buttons[i]->can_draw == NOT))
            sfRenderWindow_drawSprite(gm->window,
                button->buttons[i]->button, NULL);
}
