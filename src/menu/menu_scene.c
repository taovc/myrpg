/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** menu
*/

#include <stdlib.h>
#include "gamesys.h"
#include "./inventory/item.h"
#include "./button/button_script.h"
#include "./menu/menu_h.h"

void change_to_gameplay(game_t *gm)
{
    gm->snd_button = music_button();
    gm->now_parti = gameplay_parti;
}

void display_menu(game_t *gm, menu_t *mn)
{
    sfRenderWindow_clear(gm->window, sfBlack);
    draw_ui(mn->ui, gm);
    draw_buttons(gm, mn->button);
    if (gm->type == menu_how_to_play)
        sfRenderWindow_drawSprite(gm->window, mn->htp_page->page, NULL);
    sfRenderWindow_drawSprite(gm->window, gm->souri, NULL);
    sfRenderWindow_display(gm->window);
    update_time(gm->time);
}

static void free_menu(menu_t *mn)
{
    for (htp_t *cp; mn->htp_page; cp = mn->htp_page,
    mn->htp_page = mn->htp_page->next, free(cp));
    sfMusic_destroy(mn->snd_menu);
    free_button(mn->button->buttons);
    free(mn->button);
    free_ui(mn->ui);
    free(mn);
}

void my_menu(game_t *gm)
{
    menu_t *mn = malloc(sizeof(menu_t));

    sfRenderWindow_setMouseCursorVisible(gm->window, sfFalse);
    mn->snd_menu = play_music("./sound/sound_menu1.ogg");
    mn->fps = 120;
    mn->ui = init_ui("./config_files/menu/menu_ui.json");
    mn->button = init_struct_button("./config_files/menu/menu_button.json");
    mn->htp_page = creat_page_htp();
    sfRenderWindow_setFramerateLimit(gm->window, mn->fps);
    while (sfRenderWindow_isOpen(gm->window) && gm->now_parti == menu_parti) {
        display_menu(gm, mn);
        event_menu(gm, mn);
    }
    free_menu(mn);
}