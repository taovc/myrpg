/*
** EPITECH PROJECT, 2021
** dungeon_event
** File description:
** Dungeon events
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./inventory/inventory.h"
#include "./button/button_script.h"
#include <stdlib.h>

static void evnt_player_move(game_t *gm, play_t *game, sfVector2f pospy)
{
    if (gm->timer_spritesheet >= 0.175) {
        game->person_rt.left += 90;
        sfSprite_setTextureRect(game->person, game->person_rt);
    }
    if (game->person_rt.left >= 1260)
        game->person_rt.left = 0;
    sfSprite_setPosition(game->person, pospy);
}

static void evnt_move_person(game_t *gm, play_t *py)
{
    sfVector2f pospy = sfSprite_getPosition(py->person);

    py->person_rt.top = 127.6 * 5;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && pospy.y <= 640) {
        py->person_rt.top = 127.6 * 3, pospy.y += 4;
        random_encounter(gm, py);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && pospy.y >= 136) {
        py->person_rt.top = 127.6 * 2, pospy.y -= 4;
        random_encounter(gm, py);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && pospy.x <= 1086) {
        py->person_rt.top = 127.6 * 0, pospy.x += 4;
        random_encounter(gm, py);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && pospy.x >= 222) {
        py->person_rt.top = 127.6 * 1, pospy.x -= 4;
        random_encounter(gm, py);
    }
    evnt_player_move(gm, py, pospy);
}

static void is_in_tp(play_t *py, game_t *gm)
{
    sfVector2f pospy = sfSprite_getPosition(py->person);
    sfVector2f spawn = {650, 360};

    if (pospy.x >= 554 && pospy.x <= 758
        && pospy.y >= 296 && pospy.y <= 440) {
        py->map = py->map->next;
        py->map->leave = 0;
        py->floor++;
        sfSprite_setPosition(py->person, spawn);
        if (py->map->next == NULL)
            gm->type = end_game;
    }
}

static void talk_npc(game_t *gm, play_t *py)
{
    sfVector2f pospy = sfSprite_getPosition(py->person);

    if (pospy.x >= 218 && pospy.x <= 330 && py->map->tag == 0
        && pospy.y >= 504 && pospy.y <= 644) {
        gm->type = start_game;
    }
}

void dungeon_evnt(game_t *gm, play_t *py)
{
    evnt_move_person(gm, py);
    talk_npc(gm, py);
    if (py->map->next != NULL && py->map->leave == can_leave) {
        is_in_tp(py, gm);
    }
}