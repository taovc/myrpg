/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "gamesys.h"
#include "parser.h"
#include "./button/button.h"
#include "./button/button_script.h"
#include "my.h"
#include <stdlib.h>

static void free_all(game_t *gm)
{
    gm->snd_button ? sfMusic_destroy(gm->snd_button): 0;
    gm->snd_click ? sfMusic_destroy(gm->snd_click): 0;
    sfRenderWindow_destroy(gm->window);
    sfSprite_destroy(gm->souri);
    end_timer(gm->time);
    free(gm);
}

int is_enable_display(char *env[])
{
    int i = 0;
    char const *keyword = "DISPLAY";

    for (i = 0; env[i]; i++)
        if (my_strncmp(keyword, env[i], my_strlen(keyword)) == 0)
            break;
    if (!env[i])
        return 0;
    if (my_strlen(env[i]) == 10)
        return 1;
    else
        is_enable_display(&env[i]);
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (is_enable_display(env) == 0)
        return 0;
    game_t *gm = create_gamesys();
    void (*scene_used)() = gm->get_parti(gm->now_parti);

    while (gm->now_parti) {
        scene_used = gm->get_parti(gm->now_parti);
        if (gm->now_parti == 0)
            break;
        scene_used(gm);
    }
    free_all(gm);
    return 0;
}