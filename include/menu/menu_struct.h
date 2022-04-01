/*
** EPITECH PROJECT, 2020
** gamesys
** File description:
** Contains all the functions for the gamesys
*/

#ifndef MENU_STRUCT_H_
#define MENU_STRUCT_H_

#include "./gameplay/npc_entities.h"
#include "./gamesystem/gamesys_struct.h"
#include "./button/button.h"
#include "./inventory/inventory.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include <SFML/Window/Event.h>

typedef struct htp_s {
    sfSprite *page;
    struct htp_s *next;
    struct htp_s *pre;
} htp_t;

typedef struct menu_s {
    buttons_t *button;
    ui_t **ui;
    int fps;
    sfMusic *snd_menu;
    htp_t *htp_page;
} menu_t;

//End of program
void free_ui(ui_t **ui);
sfMusic *play_music(char *str);
sfMusic *music_click(void);
sfMusic *music_button(void);
htp_t *creat_page_htp(void);

#endif /* !MENU_STRUCT_H_ */
