/*
** EPITECH PROJECT, 2021
** deal_dmg_to_player
** File description:
** Deal damage to player
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

void go_to_home(game_t *gm, play_t *game)
{
    update_type(gm, in_game);
    sfSprite_setPosition(game->my_map, (sfVector2f){-960, -220});
    game->py_x = 21;
    game->py_y = 8;
    sfSprite_setPosition(game->person, (sfVector2f){650, 360});
}

void respawn(game_t *gm, play_t *game)
{

    update_type(gm, game->combat->last_type);
    game->stats->hp = game->stats->hp_max;
    free_combat_mobs(game->combat);
    go_to_home(gm, game);
    sfSprite_setTextureRect(game->ui[2]->ui_sprite,
    (sfIntRect){0, 0, 166, 25});
}

void dead_animation(game_t *gm, play_t *game)
{
    game->combat->player->rect.top = game->combat->player->incre.y * 6;
    game->combat->player->rect.left = 0;
    sfSprite_setTextureRect(game->combat->player->player,
        game->combat->player->rect);
    for (float time = 2.0;time > 0; time -= gm->time->delta_time)
        display_game(gm, game);
    game->combat->player->rect.top = game->combat->player->incre.y * 3;
    game->combat->player->rect.left = 0;
}

int take_damage_player(game_t *gm, play_t *game, int ted)
{
    if (game->combat->mobs[ted]->stat.atck < game->stats->def)
        return 0;
    update_hp_bar(game->ui[2]->ui_sprite,
        &game->stats->hp, (sfVector2f){game->stats->hp_max,
        (game->combat->mobs[ted]->stat.atck - game->stats->def)});
    if (game->stats->hp <= 0) {
        loose(gm, game);
        return 1;
    }
    return 0;
}
