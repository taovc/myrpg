/*
** EPITECH PROJECT, 2021
** draw_game
** File description:
** Draw game
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

static void draw_map(map_t *map, game_t *gm, play_t *game)
{
    if (game->map->tag == 1 || game->map->tag == 0)
        sfRenderWindow_drawSprite(gm->window, game->water, NULL);
    if (game->map->tag == 2)
        sfRenderWindow_drawSprite(gm->window, game->poison, NULL);
    if (game->map->tag == 3 || game->map->tag == 4)
        sfRenderWindow_drawSprite(gm->window, game->lave, NULL);
    sfRenderWindow_drawSprite(gm->window, map->map, NULL);
    if (game->map->leave == can_leave)
        sfRenderWindow_drawSprite(gm->window, game->tp, NULL);
    sfRenderWindow_drawSprite(gm->window, game->person, NULL);
}

static void draw_main_map(game_t *gm, play_t *py)
{
    sfRenderWindow_drawSprite(gm->window, py->my_map, NULL);
    if (py->is_win == 1)
        sfRenderWindow_drawSprite(gm->window, py->win_map, NULL);
    sfRenderWindow_drawSprite(gm->window, py->person, NULL);
}

void draw_game(game_t *gm, play_t *game)
{
    update_time(gm->time);
    gm->timer_spritesheet -= gm->time->delta_time;
    draw_ui(game->ui, gm);
    draw_buttons(gm, game->button);
    if (gm->type == in_dungeon)
        draw_map(game->map, gm, game);
    if (gm->type == in_game)
        draw_main_map(gm, game);
    game_conditional_draw(gm, game);
    move_every_spritesheet(gm, game);
    if (gm->type == in_skill)
        sfRenderWindow_drawText(gm->window, game->skill, NULL);
    sfRenderWindow_drawSprite(gm->window, gm->souri, NULL);
}

void display_game(game_t *gm, play_t *game)
{
    sfRenderWindow_clear(gm->window, sfBlack);
    if (game->combat->in_combat == 1)
        sfRenderWindow_drawSprite(gm->window, game->ui[0]->ui_sprite, NULL);
    draw_game(gm, game);
    sfRenderWindow_display(gm->window);
}