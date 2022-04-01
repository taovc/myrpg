/*
** EPITECH PROJECT, 2021
** init_skill
** File description:
** Init skill tree
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"
#include <stdlib.h>

void init_skill(game_t *gm, play_t *game, save_t *save)
{
    char *str = NULL;

    game->skill_type = save->skill;
    switch (game->skill_type) {
    case 0:
        str = "Skill type: NULL";
        break;
    case 1:
        str = "Skill type: Attack";
        break;
    case 2:
        str = "Skill type: Defense";
        break;
    case 3:
        str = "Skill type: HP";
        break;
    }
    game->skill = creat_text_as_file("./imgs/Font.ttf", str, 20, 20);
}
