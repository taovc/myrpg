/*
** EPITECH PROJECT, 2021
** init_combat
** File description:
** Init the combat structure
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"
#include <stdlib.h>

static void copy_mobs(mobs_t *mob, mobs_t *to_copy)
{
    mob->incre = to_copy->incre;
    mob->incre_limit = to_copy->incre_limit;
    mob->rect = to_copy->rect;
    mob->stat = to_copy->stat;
    mob->type = to_copy->type;
    mob->texture = sfTexture_copy(to_copy->texture);
    mob->mobs = sfSprite_copy(to_copy->mobs);
}

static void init_target(combat_t *combat)
{
    combat->cross = sfTexture_createFromFile(
        "./imgs/in_combat/target.png", NULL);
    combat->target = sfSprite_create();
    combat->target_nbr = 0;
    sfSprite_setTexture(combat->target, combat->cross, sfTrue);
    set_target_pos(combat);
}

static void init_hp_bar(hp_bar_t *hp, int id, sfVector2f pos)
{
    sfVector2f tmp = {pos.x, pos.y};

    hp->hp_text = sfTexture_createFromFile(mob_hp_pos[id].hp_text, NULL);
    hp->hpb_text = sfTexture_createFromFile(mob_hp_pos[id].hpb_text, NULL);
    hp->hp = sfSprite_create();
    hp->hp_bar = sfSprite_create();
    tmp.x = pos.x + mob_hp_pos[id].pos_hp.x;
    tmp.y = pos.y + (mob_hp_pos[id].pos_hp.y / 2);
    sfSprite_setTexture(hp->hp, hp->hp_text, sfTrue);
    sfSprite_setPosition(hp->hp, tmp);
    tmp.x -= 30;
    tmp.y -= 13;
    sfSprite_setTexture(hp->hp_bar, hp->hpb_text, sfTrue);
    sfSprite_setPosition(hp->hp_bar, tmp);
}

static void init_combat_mobs(mobs_t *mob, mob_list_t *mobs_list,
int i, int is_boss)
{
    int random = rand() % (mobs_list->nbr_mobs - boss);

    if (is_boss == 1)
        random = 4;
    copy_mobs(mob, mobs_list->mobs_list[random]);
    sfSprite_setPosition(mob->mobs, combat_pos[i]);
    mob->hp_bar = malloc(sizeof(hp_bar_t));
    init_hp_bar(mob->hp_bar, mob->type, combat_pos[i]);
}

void init_combat(play_t *game, game_t *gm, int nbr_mobs)
{
    int is_boss = 0;

    srand(sfClock_getElapsedTime(gm->time->clock).microseconds);
    game->combat->last_type = gm->type;
    game->combat->mobs = malloc(sizeof(mobs_t *) * (nbr_mobs + 1));
    game->combat->mobs[nbr_mobs] = NULL;
    sfSprite_setPosition(game->combat->player->player, combat_pos[4]);
    if (nbr_mobs == 4) {
        nbr_mobs = 1;
        is_boss = 1;
    }
    for (int i = 0; i < nbr_mobs; ++i) {
        game->combat->mobs[i] = malloc(sizeof(mobs_t));
        init_combat_mobs(game->combat->mobs[i], game->mobs_list, i, is_boss);
    }
    game->combat->in_combat = 1;
    game->combat->nbr_mobs = nbr_mobs;
    init_target(game->combat);
    update_type(gm, in_combat);
}