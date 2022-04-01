/*
** EPITECH PROJECT, 2020
** gamesys
** File description:
** Contains all the functions for the gamesys
*/

#ifndef GAMESYS_H_
#define GAMESYS_H_

#include <SFML/Graphics.h>
#include "./button/button.h"
#include "ui.h"
#include "quest.h"
#include "time.h"
#include "all_parti.h"
#include "./gamesystem/gamesys_struct.h"
#include "music.h"

//Start of program
game_t *create_gamesys(void);
buttons_t *init_struct_button(char *filepath);
ui_t **init_ui(char *filepath);
void init_quest(game_t *gm);
void evnt_switch(sfEvent evnt, game_t *gm);
music_alone_t **init_music(char *filepath);

//Init a json
int get_json_args(json_t *ui_parser, char *compare, int str_len);
void get_json_spritesheet(json_t *parser, sfIntRect *rect);
void get_json_increment(json_t *parser, sfVector2f *incre);
void get_json_pos(json_t *parser, sfVector2f *pos);
void get_json_increment_limit(json_t *parser, sfVector2f *limit_incre);
sfTexture *get_json_texture(json_t *parser, int *text);
void json_int(json_t *parser, char *cmp, int len, int *value);

//During the program
void move_spritesheet(sfSprite *sprite, sfIntRect *rect,
sfVector2f *incre, sfVector2f limit);
void interact_button(game_t *gm, void *scene, buttons_t *button);
void click_on_button(game_t *gm, void *scene, buttons_t *button);
void draw_ui(ui_t **ui, game_t *gm);
void draw_buttons(game_t *gm, buttons_t *button);
void update_type(game_t *gm, int new_type);
//End of program

#endif /* !GAMESYS_H_ */
