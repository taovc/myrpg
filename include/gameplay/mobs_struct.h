/*
** EPITECH PROJECT, 2021
** mobs_struct
** File description:
** Mobs structure
*/

#ifndef MOBS_STRUCT_H_
#define MOBS_STRUCT_H_

#include <SFML/Graphics.h>

typedef struct stat_s {
    int hp;
    int hp_max;
    int atck;
}stat_t;

typedef struct hp_bar_s {
    sfTexture *hp_text;
    sfSprite *hp;
    sfTexture *hpb_text;
    sfSprite *hp_bar;
}hp_bar_t;

typedef struct mobs_s {
    sfSprite *mobs;
    sfTexture *texture;
    sfVector2f incre;
    sfVector2f incre_limit;
    sfIntRect rect;
    stat_t stat;
    hp_bar_t *hp_bar;
    int type;
}mobs_t;

typedef struct pos_s {
    sfVector2f pos_hp;
    sfVector2f pos_hpb;
    char *hp_text;
    char *hpb_text;
}pos_t;

static const int boss = 1;

static const pos_t mob_hp_pos[] = {
    { {-30, -27}, {-60, -40 }, "./imgs/in_combat/health.png",
    "./imgs/in_combat/health_bar.png"},
    { {0, -70}, {0, -87 }, "./imgs/in_combat/health.png",
    "./imgs/in_combat/health_bar.png"}
};
#endif /* !MOBS_STRUCT_H_ */
