/*
** EPITECH PROJECT, 2021
** draw_combat
** File description:
** Draw combat
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

void draw_combat(game_t *gm, combat_t *combat)
{
    if (gm->type != in_combat || combat->in_combat == 0)
        return;
    for (int i = 0; combat->mobs[i]; ++i)
        if (combat->mobs[i]->mobs) {
            sfRenderWindow_drawSprite(gm->window, combat->mobs[i]->mobs, NULL);
            sfRenderWindow_drawSprite(gm->window,
                combat->mobs[i]->hp_bar->hp, NULL);
            sfRenderWindow_drawSprite(gm->window,
                combat->mobs[i]->hp_bar->hp_bar, NULL);
        }
    sfRenderWindow_drawSprite(gm->window, combat->player->player, NULL);
    sfRenderWindow_drawSprite(gm->window, combat->target, NULL);
}
