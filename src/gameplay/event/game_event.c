/*
** EPITECH PROJECT, 2021
** game_event
** File description:
** Game event
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

static void key_skill(game_t *gm)
{
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        gm->now_parti = exit_parti;
        sfRenderWindow_close(gm->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        if (gm->type == in_skill)
            update_type(gm, gm->last_type);
        else
            update_type(gm, in_skill);
    }
}

static void key_pressed(game_t *gm, play_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) && game->combat->in_combat == 0) {
        if (gm->type == inventory)
            update_type(gm, gm->last_type);
        else
            update_type(gm, inventory);
        update_inv_stat(game->inventories->inv_stat, game->stats);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (gm->type == in_pause)
            update_type(gm, gm->last_type);
        else
            update_type(gm, in_pause);
    }
    key_skill(gm);
}

static void start_end_game(game_t *gm, play_t *py)
{
    if (gm->type == end_game) {
        py->is_win = 1;
        update_type(gm, in_game);
        respawn(gm, py);
    }
    if (gm->type == start_game) {
        update_type(gm, in_dungeon);
        sfSprite_setPosition(py->person, (sfVector2f){300, 360});
        py->map->leave = can_leave;
    }
    if (gm->type == in_skill)
        skill_tree_evnt(gm, py);
}

static void evnt_switch_game(game_t *gm, play_t *py)
{
    switch (gm->event.type) {
    case sfEvtClosed:
        gm->now_parti = exit_parti;
        sfRenderWindow_close(gm->window);
        break;
    case sfEvtMouseButtonPressed:
        start_end_game(gm, py);
        break;
    case sfEvtKeyPressed:
        key_pressed(gm, py);
        break;
    default:
        break;
    }
}

void event_game(game_t *gm, play_t *game)
{
    if (gm->music_open == 0)
        sfMusic_setVolume(game->snd_map, 0.0);
    else
        sfMusic_setVolume(game->snd_map, 100.0);
    while (sfRenderWindow_pollEvent(gm->window, &gm->event)) {
        evnt_switch_game(gm, game);
        change_pos_souri(gm->souri, gm->window);
        click_on_button(gm, game, game->button);
        get_target(gm, game);
    }
}
