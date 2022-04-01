/*
** EPITECH PROJECT, 2021
** draw_inventories
** File description:
** Draw the inventories
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

void draw_inventories(game_t *gm, play_t *game)
{
    if (gm->type != inventory)
        return;
    for (int i = 0; game->inventories->inventory[i]; ++i)
        sfRenderWindow_drawSprite(gm->window,
        game->inventories->inventory[i]->sprite, NULL);
    for (int i = 0; game->inventories->equip_inventory[i]; ++i)
        sfRenderWindow_drawSprite(gm->window,
        game->inventories->equip_inventory[i]->sprite, NULL);
    sfRenderWindow_drawText(gm->window, game->inventories->inv_stat->max_hp,
    NULL);
    sfRenderWindow_drawText(gm->window, game->inventories->inv_stat->dmg, NULL);
    sfRenderWindow_drawText(gm->window, game->inventories->inv_stat->def, NULL);
    sfRenderWindow_drawText(gm->window, game->inventories->inv_stat->lvl, NULL);
}