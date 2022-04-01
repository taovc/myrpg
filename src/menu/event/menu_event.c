/*
** EPITECH PROJECT, 2021
** menu_event
** File description:
** Menu event
*/

#include "gamesys.h"
#include "./menu/menu_struct.h"
#include "./button/button_script.h"

static void exit_game_by_menu(game_t *gm)
{
    switch (gm->event.type) {
    case sfEvtClosed:
        gm->now_parti = exit_parti;
        sfRenderWindow_close(gm->window);
        break;
    default:
        break;
    }
}

static htp_t *evnt_switch_menu(game_t *gm, htp_t *page)
{
    exit_game_by_menu(gm);
    if (gm->event.type == sfEvtMouseButtonPressed &&
        gm->event.mouseButton.button == sfMouseLeft &&
        gm->type == menu_how_to_play && page->next != NULL)
        return page->next;
    if (gm->event.type == sfEvtMouseButtonPressed &&
        gm->event.mouseButton.button == sfMouseRight &&
        gm->type == menu_how_to_play && page->pre != NULL)
        return page->pre;
    return page;
}

void event_menu(game_t *gm, menu_t *mn)
{
    if (gm->music_open == 0)
        sfMusic_setVolume(mn->snd_menu, 0.0);
    else
        sfMusic_setVolume(mn->snd_menu, 100.0);
    while (sfRenderWindow_pollEvent(gm->window, &gm->event)) {
        change_pos_souri(gm->souri, gm->window);
        click_on_button(gm, mn, mn->button);
        mn->htp_page = evnt_switch_menu(gm, mn->htp_page);
    }
}
