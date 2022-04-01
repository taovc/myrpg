/*
** EPITECH PROJECT, 2021
** interact_button
** File description:
** Interact with the button
*/

#include "gamesys.h"
#include "./button/button_script.h"

static int button_mouseover(button_t *button, sfVector2i mouse_pos,
sfFloatRect sprite_pos, int type)
{
    if (button->type != type || button->can_draw == CONST
        || button->can_draw == NOT)
        return 0;
    if (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y)) {
        if (button->mouseover == 0) {
            sfSprite_setTexture(button->button,
                button->button_mouseover, sfFalse);
            button->rect.top += (int)button->incre.y;
            sfSprite_setTextureRect(button->button, button->rect);
            button->mouseover = 1;
        }
        return 1;
    } else if (button->mouseover == 1) {
        button->rect.top -= (int)button->incre.y;
        sfSprite_setTexture(button->button, button->button_text, sfFalse);
        sfSprite_setTextureRect(button->button, button->rect);
        button->mouseover = 0;
    }
    return 0;
}

static void button_script(game_t *gm, void *scene, button_t *button)
{
    buttons_arr[button->type].button_arr[button->script].fc(gm, scene);
}

static void exception(game_t *gm, buttons_t *button)
{
    if (gm->now_parti == gameplay_parti) {
        button->buttons[0]->can_draw = DROW_TOUCH;
        button->buttons[2]->can_draw = DROW_TOUCH;
    }
}

void click_on_button(game_t *gm, void *scene, buttons_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gm->window);
    sfFloatRect sprite_pos;

    for (int i = 0, over = 0; button->buttons[i]; i++) {
        sprite_pos = sfSprite_getGlobalBounds(button->buttons[i]->button);
        over = button_mouseover(button->buttons[i], mouse_pos,
            sprite_pos, gm->type);
        if (over == 0 && gm->event.type == sfEvtMouseButtonReleased &&
            button->buttons[i]->can_draw == TOUCH) {
            button->buttons[i]->can_draw = CONST;
            exception(gm, button);
        }
        if (over == 1 && gm->event.type == sfEvtMouseButtonReleased &&
            gm->event.key.code == sfMouseLeft) {
            button_script(gm, scene, button->buttons[i]);
            break;
        }
    }
}
