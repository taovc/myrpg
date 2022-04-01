/*
** EPITECH PROJECT, 2021
** skill
** File description:
** skill.c
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include "./button/button_script.h"

static void attack_branch(game_t *gm, play_t *py)
{
    if (gm->event.mouseButton.x >= 70 && gm->event.mouseButton.x <= 430
        && gm->event.mouseButton.y >= 190 && gm->event.mouseButton.y <= 810) {
        py->skill = creat_text_as_file
            ("./imgs/Font.ttf", "Skill type: Attack", 20, 20);
        if (py->skill_type != 1)
            py->stats->atck += 5;
        if (py->skill_type == 2)
            py->stats->def -= 5;
        if (py->skill_type == 3)
            py->stats->hp_max -= 10;
        update_hp_bar(py->ui[2]->ui_sprite, &py->stats->hp,
            (sfVector2f){py->stats->hp_max, 0});
        update_inv_stat(py->inventories->inv_stat, py->stats);
        py->skill_type = 1;
    }
}

static void def_branch(game_t *gm, play_t *py)
{
    if (gm->event.mouseButton.x >= 70 + 535 && gm->event.mouseButton.x <= 965
        && gm->event.mouseButton.y >= 190 && gm->event.mouseButton.y <= 810) {
        py->skill = creat_text_as_file
            ("./imgs/Font.ttf", "Skill type: Defense", 20, 20);
        if (py->skill_type != 2)
            py->stats->def += 5;
        if (py->skill_type == 1)
            py->stats->atck -= 5;
        if (py->skill_type == 3)
            py->stats->hp_max -= 10;
        update_hp_bar(py->ui[2]->ui_sprite, &py->stats->hp,
            (sfVector2f){py->stats->hp_max, 0});
        update_inv_stat(py->inventories->inv_stat, py->stats);
        py->skill_type = 2;
    }
}

static void hp_branch(game_t *gm, play_t *py)
{
    if (gm->event.mouseButton.x >= 980 && gm->event.mouseButton.x <= 1500
    && gm->event.mouseButton.y >= 190 && gm->event.mouseButton.y <= 810) {
        py->skill = creat_text_as_file
            ("./imgs/Font.ttf", "Skill type: HP", 20, 20);
        if (py->skill_type != 3)
            py->stats->hp_max += 10;
        if (py->skill_type == 1)
            py->stats->atck -= 5;
        if (py->skill_type == 2)
            py->stats->def -= 5;
        update_hp_bar(py->ui[2]->ui_sprite, &py->stats->hp,
            (sfVector2f){py->stats->hp_max, 0});
        update_inv_stat(py->inventories->inv_stat, py->stats);
        py->skill_type = 3;
    }
}

void skill_tree_evnt(game_t *gm, play_t *py)
{
    attack_branch(gm, py);
    def_branch(gm, py);
    hp_branch(gm, py);
}