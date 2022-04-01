/*
** EPITECH PROJECT, 2021
** gameplay_struct
** File description:
** Gameplay structure
*/

#ifndef GAMEPLAY_STRUCT_H_
#define GAMEPLAY_STRUCT_H_

#include "./inventory/inventory.h"
#include "./gameplay/mobs_struct.h"
#include "./gameplay/player_struct.h"
#include "music.h"

static const int can_leave = 1;

typedef struct map_s {
    sfSprite *map;
    int tag;
    int leave;
    struct map_s *next;
} map_t;

typedef struct combat_s {
    mobs_t **mobs;
    player_t *player;
    sfSprite *target;
    sfTexture *cross;
    int target_nbr;
    int nbr_mobs;
    int in_combat;
    int last_type;
}combat_t;


typedef struct mob_list_s {
    mobs_t **mobs_list;
    int nbr_mobs;
}mob_list_t;

typedef struct player_stat_s {
    int hp;
    int hp_max;
    int atck;
    int def;
    int lvl;
    int exp;
}player_stat_t;

typedef struct inventory_stat_s{
    sfText *max_hp;
    sfText *def;
    sfText *dmg;
    sfText *lvl;
    sfFont *font;
}inventory_stat_t;

typedef struct all_inventory_s {
    inventory_t **inventory;
    inventory_stat_t *inv_stat;
    equipped_inventory_t **equip_inventory;
}all_inventory_t;

typedef struct play_s {
    buttons_t *button;
    ui_t **ui;
    music_t *music;
    all_inventory_t *inventories;
    npc_t **npc;
    mob_list_t *mobs_list;
    combat_t *combat;
    sfSprite *person;
    sfIntRect person_rt;
    int selectioned_item;
    map_t *map;
    map_t *head_map;
    player_stat_t *stats;
    sfSprite *lave;
    sfIntRect lave_rect;
    sfSprite *water;
    sfSprite *poison;
    sfSprite *tp;
    sfSprite *my_map;
    sfSprite *win_map;
    sfText *skill;
    int skill_type;
    char **map_txt;
    int py_x;
    int py_y;
    sfMusic *snd_map;
    int is_win;
    int floor;
} play_t;

typedef struct attack_tmp_s {
    sfFloatRect ted_pos;
    sfFloatRect ter_pos;
    sfVector2f move;
    sfVector2f pos;
}attack_tmp_t;

static const sfVector2f combat_pos[] = {
    {800, 290},
    {800, 390},
    {800, 490},
    {800, 590},
    {300, 400}
};

static const float one_sec = 0.2;

#endif /* !GAMEPLAY_STRUCT_H_ */
