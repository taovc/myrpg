/*
** EPITECH PROJECT, 2021
** attack_mobs_aoe
** File description:
** Attack mobs in aoe
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

static int reduce_dmg_aoe(int dmg, int i, int target)
{
    int tmp = dmg;
    int dif = i - target;

    if (dif == 0)
        return tmp;
    else if (dif > 0)
        for (int j = 0; j < dif; ++j)
            tmp = tmp / 2;
    else
        for (int j = 0; dif < j; ++dif)
            tmp = tmp / 2;
    return tmp;
}

static int mobs_take_dmg(game_t *gm, play_t *game, int i)
{
    if (game->combat->mobs[i]->stat.hp <= 0) {
        kill_mobs(gm, game, i);
        if (check_dead(gm, game) == 1)
            return 1;
        get_new_target(game->combat);
    }
    return 0;
}

void take_aoe_damage(game_t *gm, play_t *game, int target)
{
    int dmg = game->stats->atck * 0.7;

    if (check_dead(gm, game) == 1 || game->combat->mobs == NULL)
        return;
    for (int i = 0, tmp = 0, finished = 0; game->combat->mobs &&
    game->combat->mobs[i] && finished == 0; ++i) {
        if (game->combat->mobs[i]->mobs) {
            tmp = reduce_dmg_aoe(dmg, i, target);
            update_hp_bar(game->combat->mobs[i]->hp_bar->hp,
                &game->combat->mobs[i]->stat.hp, (sfVector2f)
                {game->combat->mobs[i]->stat.hp_max, tmp});
            finished = mobs_take_dmg(gm, game, i);
        }
    }
}

attack_tmp_t init_tmp(combat_t *combat, int target)
{
    attack_tmp_t tmp = {
        sfSprite_getGlobalBounds(combat->mobs[target]->mobs),
        sfSprite_getGlobalBounds(combat->player->player), {(tmp.ted_pos.left
            - (tmp.ter_pos.left)) / 20,
            (tmp.ted_pos.top - tmp.ter_pos.top) / 20},
            {tmp.ter_pos.left, tmp.ter_pos.top}};

    return tmp;
}

void attack_mobs_aoe(game_t *gm, play_t *game)
{
    int ted = game->combat->target_nbr;
    attack_tmp_t tmp = init_tmp(game->combat, ted);
    sfSprite *effect = sfSprite_create();
    sfTexture *texture = NULL;

    texture = sfTexture_createFromFile("./imgs/effects/aoe_dmg.png", NULL);
    sfSprite_setTexture(effect, texture, sfTrue);
    sfSprite_setPosition(effect, (sfVector2f){tmp.ted_pos.left -
        500, tmp.ted_pos.top - (472 - tmp.ted_pos.height)});
    attack_animation(gm, game, &tmp);
    take_aoe_damage(gm, game, ted);
    fallback_animation(gm, game, &tmp, effect);
    sfTexture_destroy(texture);
    sfSprite_destroy(effect);
    for (int i = 0; game->combat->mobs && game->combat->mobs[i]; ++i)
        if (game->combat->mobs[i]->mobs && attack_player(gm, game, i) == 1)
            return;
}
