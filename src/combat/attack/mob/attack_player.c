/*
** EPITECH PROJECT, 2021
** attack_player
** File description:
** Attack the player
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

static void attack_animation_m(game_t *gm, play_t *game, attack_tmp_t *tmp,
mobs_t *mob)
{
    mob->rect.top = mob->incre.y * 0;
    sfSprite_setTextureRect(mob->mobs, mob->rect);
    for (float time = 0.02;; time -= gm->time->delta_time) {
        if (tmp->pos.x <= (tmp->ted_pos.left + tmp->ter_pos.width))
            break;
        sfRenderWindow_drawSprite(gm->window, mob->mobs, NULL);
        display_game(gm, game);
        change_pos_souri(gm->souri, gm->window);
        if (time <= 0.0) {
            time = 0.02;
            tmp->pos.x += tmp->move.x;
            tmp->pos.y += tmp->move.y;
            sfSprite_setPosition(mob->mobs, tmp->pos);
        }
    }
    mob->rect.top = mob->incre.y * 2;
    mob->rect.left = 0;
    sfSprite_setTextureRect(mob->mobs, mob->rect);
}

static void hit_animation_m(game_t *gm, play_t *game)
{
    game->combat->player->rect.top = game->combat->player->incre.y * 6;
    game->combat->player->rect.left = 0;
    sfSprite_setTextureRect(game->combat->player->player,
        game->combat->player->rect);
    sfMusic_stop(game->music->sound_eff[1]->music);
    sfMusic_play(game->music->sound_eff[1]->music);
    for (float time = 0.4; time > 0; time -= gm->time->delta_time)
        display_game(gm, game);
    game->combat->player->rect.top = game->combat->player->incre.y * 5;
    sfSprite_setTextureRect(game->combat->player->player,
        game->combat->player->rect);
}

static void fallback_animation_m(game_t *gm, play_t *game, attack_tmp_t *tmp,
mobs_t *mob)
{
    hit_animation_m(gm, game);
    for (float time = 0.02;; time -= gm->time->delta_time) {
        if (tmp->pos.x >= combat_pos[game->combat->target_nbr].x)
            break;
        display_game(gm, game);
        change_pos_souri(gm->souri, gm->window);
        if (time <= 0.0) {
            time = 0.02;
            tmp->pos.x -= tmp->move.x;
            tmp->pos.y -= tmp->move.y;
            sfSprite_setPosition(mob->mobs, tmp->pos);
        }
    }
}

int attack_player(game_t *gm, play_t *game, int ter)
{
    attack_tmp_t tmp = {sfSprite_getGlobalBounds(game->combat->player->player),
        sfSprite_getGlobalBounds(game->combat->mobs[ter]->mobs),
        {((tmp.ted_pos.left - tmp.ter_pos.left) / 20),
        ((tmp.ted_pos.top - tmp.ter_pos.top) / 20)},
        {tmp.ter_pos.left, tmp.ter_pos.top}};

    attack_animation_m(gm, game, &tmp, game->combat->mobs[ter]);
    if (take_damage_player(gm, game, ter) == 1)
        return 1;
    fallback_animation_m(gm, game, &tmp, game->combat->mobs[ter]);
    return 0;
}
