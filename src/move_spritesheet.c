/*
** EPITECH PROJECT, 2021
** move_spritesheet
** File description:
** Move the spritesheet of a npc
*/

#include "gamesys.h"
#include "./button/button_script.h"
#include "./gameplay/gameplay.h"

void move_spritesheet(sfSprite *sprite, sfIntRect *rect,
sfVector2f *incre, sfVector2f limit)
{
    if (incre->x == 0)
        return;
    (*rect).left += incre->x;
    if (rect->left >= limit.x) {
        (*rect).left = 0;
    }
    sfSprite_setTextureRect(sprite, *rect);
}

static void move_lave_water(game_t *gm, play_t *game, int type)
{
    if (gm->timer_spritesheet <= 0.0) {
        gm->timer_spritesheet = one_sec;
        game->lave_rect.left += 10;
        if (type == 0)
            sfSprite_setTextureRect(game->water, game->lave_rect);
        if (type == 1)
            sfSprite_setTextureRect(game->poison, game->lave_rect);
        if (type == 2)
            sfSprite_setTextureRect(game->lave, game->lave_rect);
    }
    if (game->lave_rect.left == 600)
        game->lave_rect.left = 0;
}

void move_every_spritesheet(game_t *gm, play_t *game)
{
    if (gm->type == in_dungeon) {
        if (game->map->tag == 1 || game->map->tag == 0)
            move_lave_water(gm, game, 0);
        if (game->map->tag == 2)
            move_lave_water(gm, game, 1);
        if (game->map->tag == 3 || game->map->tag == 4)
            move_lave_water(gm, game, 2);
    }
    if (gm->timer_spritesheet <= 0.0) {
        gm->timer_spritesheet = one_sec;
        move_npc_spritesheet(gm, game);
        if (gm->type == in_combat && game->combat->in_combat == 1)
            move_combat_spritesheet(gm, game->combat);
    }
}