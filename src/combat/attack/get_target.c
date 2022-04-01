/*
** EPITECH PROJECT, 2021
** get_target
** File description:
** Get the target
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

void set_target_pos(combat_t *combat)
{
    sfVector2f pos;

    pos.x = combat_pos[combat->target_nbr].x +
        (combat->mobs[combat->target_nbr]->rect.width / 2);
    pos.y = combat_pos[combat->target_nbr].y; +
        (combat->mobs[combat->target_nbr]->rect.height / 2);
    sfSprite_setPosition(combat->target, pos);
}

void get_target(game_t *gm, play_t *game)
{
    sfFloatRect hitbox;
    sfVector2i mouse_pos;

    if ((gm->event.type != sfEvtMouseButtonReleased &&
        gm->event.key.code != sfMouseLeft) || gm->type != in_combat
        || game->combat->in_combat == 0)
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(gm->window);
    for (int i = 0; game->combat->mobs[i]; ++i) {
        if (!game->combat->mobs[i]->mobs)
            continue;
        hitbox = sfSprite_getGlobalBounds(game->combat->mobs[i]->mobs);
        if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y)
            == sfTrue) {
            game->combat->target_nbr = i;
            break;
        }
    }
    set_target_pos(game->combat);
}