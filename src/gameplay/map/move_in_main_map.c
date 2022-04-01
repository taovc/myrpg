/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"


static void get_position_map(sfVector2f posmp, play_t *py)
{
    if ((int)posmp.y > -220)
        py->py_y = 8 - (((int)posmp.y - (-220)) / 78);
    if ((int)posmp.y <= -220)
        py->py_y = 8 + (((-220) - (int)posmp.y) / 78);
    if ((int)posmp.x > (-960))
        py->py_x = 21 - (int)((posmp.x - (-960.0)) / 85);
    if ((int)posmp.x <= (-960))
        py->py_x = 21 + (int)(((-960.0) - posmp.x) / 85);
}

static map_t *get_floor(int etage, map_t *head)
{
    for (int i = 0; i < etage && head->next; head = head->next, i++);
    return head;
}

static void go_in_dungeon(game_t *gm, play_t *py)
{
    sfVector2f posmp = sfSprite_getPosition(py->my_map);

    if (posmp.y == -1076.0 && py->is_win == 0 &&
    (posmp.x >= (-1972.0) && posmp.x <= (-1900.0))) {
        py->map = get_floor(py->floor, py->head_map);
        gm->type = in_dungeon;
    }
    if (posmp.x == -2152.0 && py->is_win == 0 && posmp.y == 92.0) {
        py->map = get_floor(py->floor, py->head_map);
        gm->type = in_dungeon;
    }
    if (posmp.x == 148.0 && py->is_win == 0 && posmp.y == 16.0) {
        py->map = get_floor(py->floor, py->head_map);
        gm->type = in_dungeon;
    }
    if (posmp.x >= -1024.0 && posmp.x <= -900.0 && posmp.y == -140.0)
        gm->type = in_skill;
}

static void evnt_player_move(game_t *gm, play_t *game, sfVector2f posmp)
{
    if (gm->timer_spritesheet >= 0.175) {
        game->person_rt.left += 90;
        sfSprite_setTextureRect(game->person, game->person_rt);
    }
    if (game->person_rt.left >= 1260)
        game->person_rt.left = 0;
    sfSprite_setPosition(game->my_map, posmp);
    sfSprite_setPosition(game->win_map, posmp);
    go_in_dungeon(gm, game);
}

void main_map_evnt(game_t *gm, play_t *py)
{
    sfVector2f posmp = sfSprite_getPosition(py->my_map);

    get_position_map(posmp, py);
    py->person_rt.top = 127.6 * 5;
    if (sfKeyboard_isKeyPressed(sfKeyDown)
        && py->map_txt[py->py_y + 1][py->py_x] == '0')
        py->person_rt.top = 127.6 * 3, posmp.y -= 4.0;
    if (sfKeyboard_isKeyPressed(sfKeyUp)
        && py->map_txt[py->py_y - 1][py->py_x] == '0')
        py->person_rt.top = 127.6 * 2, posmp.y += 4.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight)
        && py->map_txt[py->py_y][py->py_x + 1] == '0')
        py->person_rt.top = 127.6 * 0, posmp.x -= 4.0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
        && py->map_txt[py->py_y][py->py_x - 1] == '0')
        py->person_rt.top = 127.6 * 1, posmp.x += 4.0;
    evnt_player_move(gm, py, posmp);
}