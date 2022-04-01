/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** char include
*/

#ifndef CHAR_H_
#define CHAR_H_

#include <SFML/Graphics.h>
#include "gamesys.h"

void move_char(game_t *gm);

typedef struct char_s {
    sfSprite *s_char;
    sfTexture *t_char;
    sfVector2f *v_char;
}char_t;


#endif /* !CHAR_H_ */
