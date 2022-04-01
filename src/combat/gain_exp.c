/*
** EPITECH PROJECT, 2021
** gain_exp
** File description:
** Gain exp
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

void update_xp_bar(sfSprite *xp, int exp)
{
    int width = 0;

    sfSprite_setTextureRect(xp, (sfIntRect){0, 0, 316, 28});
    width = (316 / 100) * (exp);
    if (width > 316)
        width = 316;
    sfSprite_setTextureRect(xp, (sfIntRect){0, 0, width, 28});
}

static void gain_level(play_t *game, int lvl_gain)
{
    for (int i = 0; i < lvl_gain; ++i) {
        ++game->stats->lvl;
        game->stats->hp_max += 2;
        if (game->stats->lvl % 2 != 0)
            game->stats->atck += 1;
    }
}

void gain_exp(play_t *game, int exp)
{
    int lvl_gain = 0;

    game->stats->exp += exp;
    if (game->stats->exp >= 100) {
        lvl_gain = game->stats->exp / 100;
        game->stats->exp -= lvl_gain * 100;
        gain_level(game, lvl_gain);
    }
    update_inv_stat(game->inventories->inv_stat, game->stats);
    update_xp_bar(game->ui[9]->ui_sprite, game->stats->exp);
}