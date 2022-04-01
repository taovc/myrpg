/*
** EPITECH PROJECT, 2021
** attack_mobs
** File description:
** Attack the mobs
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void attack_animation(game_t *gm, play_t *game, attack_tmp_t *tmp)
{
    game->combat->player->rect.top = game->combat->player->incre.y * 0;
    sfSprite_setTextureRect(game->combat->player->player,
        game->combat->player->rect);
    for (float time = 0.02;; time -= gm->time->delta_time) {
        if (tmp->pos.x >= (tmp->ted_pos.left - tmp->ted_pos.width))
            break;
        display_game(gm, game);
        change_pos_souri(gm->souri, gm->window);
        if (time <= 0.0) {
            time = 0.02;
            tmp->pos.x += tmp->move.x;
            tmp->pos.y += tmp->move.y;
            sfSprite_setPosition(game->combat->player->player, tmp->pos);
        }
    }
    game->combat->player->rect.top = game->combat->player->incre.y * 4;
    game->combat->player->rect.left = 0;
    sfSprite_setTextureRect(game->combat->player->player,
    game->combat->player->rect);
    hit_animation(gm, game, tmp->pos);
}


void fallback_animation(game_t *gm, play_t *game, attack_tmp_t *tmp,
sfSprite *effect)
{
    for (float time = 0.02;; time -= gm->time->delta_time) {
        sfRenderWindow_clear(gm->window, sfGreen);
        sfRenderWindow_drawSprite(gm->window, game->ui[0]->ui_sprite, NULL);
        if (effect)
            sfRenderWindow_drawSprite(gm->window, effect, NULL);
        if (tmp->pos.x <= combat_pos[4].x)
            break;
        draw_game(gm, game);
        sfRenderWindow_display(gm->window);
        change_pos_souri(gm->souri, gm->window);
        if (time <= 0.0) {
            time = 0.02;
            tmp->pos.x -= tmp->move.x;
            tmp->pos.y -= tmp->move.y;
            sfSprite_setPosition(game->combat->player->player, tmp->pos);
        }
    }
}

void attack_mobs(game_t *gm, play_t *game)
{
    int ted = game->combat->target_nbr;
    attack_tmp_t tmp = {
        sfSprite_getGlobalBounds(game->combat->mobs[ted]->mobs),
        sfSprite_getGlobalBounds(game->combat->player->player),
        {(tmp.ted_pos.left - (tmp.ter_pos.left)) / 20, (tmp.ted_pos.top
        - tmp.ter_pos.top) / 20}, {tmp.ter_pos.left, tmp.ter_pos.top}};

    attack_animation(gm, game, &tmp);
    take_damage_mobs(gm, game, game->combat->target_nbr);
    fallback_animation(gm, game, &tmp, NULL);
    for (int i = 0; game->combat->mobs && game->combat->mobs[i]; ++i) {
        if (game->combat->mobs[i]->mobs && attack_player(gm, game, i) == 1)
            return;
    }
}
