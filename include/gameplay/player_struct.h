/*
** EPITECH PROJECT, 2021
** player_struct
** File description:
** Player struct
*/

#ifndef PLAYER_STRUCT_H_
#define PLAYER_STRUCT_H_

typedef struct player_s {
    sfSprite *player;
    sfTexture *texture;
    sfVector2f incre;
    sfVector2f incre_limit;
    sfIntRect rect;
}player_t;

#endif /* !PLAYER_STRUCT_H_ */
