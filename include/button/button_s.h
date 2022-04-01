/*
** EPITECH PROJECT, 2021
** button_s
** File description:
** Button structures
*/

#ifndef BUTTON_S_H_
#define BUTTON_S_H_

#include <SFML/Graphics.h>

typedef struct button_s {
    sfSprite *button;
    sfTexture *button_text;
    sfTexture *button_mouseover;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f incre;
    int type;
    int script;
    int mouseover;
    int can_draw;
}button_t;

#endif /* !BUTTON_S_H_ */
