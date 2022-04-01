/*
** EPITECH PROJECT, 2021
** ui
** File description:
** Ui header file
*/

#ifndef UI_H_
#define UI_H_

#include <SFML/Graphics.h>

typedef struct ui_s {
    int type;
    sfSprite *ui_sprite;
    sfTexture *ui_texture;
    int can_draw;
}ui_t;

#endif /* !UI_H_ */
