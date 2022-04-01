/*
** EPITECH PROJECT, 2021
** hit_animation
** File description:
** Hit animation
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

static void draw_hit_animation(game_t *gm, play_t *game, sfSprite *slash,
sfIntRect rect)
{
    for (float time = 0.7, eff_time = 0.2; time > 0;
        time -= gm->time->delta_time, eff_time -= gm->time->delta_time) {
        if (eff_time <= 0.0) {
            eff_time = 0.2;
            rect.left += 80;
            sfSprite_setTextureRect(slash, rect);
        }
        sfRenderWindow_clear(gm->window, sfGreen);
        sfRenderWindow_drawSprite(gm->window, game->ui[0]->ui_sprite, NULL);
        draw_game(gm, game);
        sfRenderWindow_drawSprite(gm->window, slash, NULL);
        sfRenderWindow_display(gm->window);
    }
}

static void setup_hit_animation(game_t *gm, play_t *game, sfVector2f pos)
{
    sfTexture *slash_eff = sfTexture_createFromFile(
        "./imgs/effects/slash_effect.png", NULL);
    sfIntRect rect = {0, 0, 80, 80};
    sfSprite *slash = sfSprite_create();

    sfSprite_setTexture(slash, slash_eff, sfTrue);
    sfSprite_setTextureRect(slash, rect);
    sfSprite_setPosition(slash, pos);
    draw_hit_animation(gm, game, slash, rect);
    sfTexture_destroy(slash_eff);
    sfSprite_destroy(slash);
}

void hit_animation(game_t *gm, play_t *game, sfVector2f pos)
{
    game->combat->player->incre.x *= 3;
    setup_hit_animation(gm, game, pos);
    sfMusic_stop(game->music->sound_eff[0]->music);
    sfMusic_play(game->music->sound_eff[0]->music);
    game->combat->player->incre.x /= 3;
    game->combat->player->rect.top = game->combat->player->incre.y * 3;
    sfSprite_setTextureRect(game->combat->player->player,
        game->combat->player->rect);
}
