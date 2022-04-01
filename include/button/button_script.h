/*
** EPITECH PROJECT, 2021
** button_script
** File description:
** Button_script header file
*/

#ifndef BUTTON_SCRIPT_H_
#define BUTTON_SCRIPT_H_

#include <stdio.h>
#include "button_script_proto.h"
#include "./gamesystem/gamesys_struct.h"
#include "./menu/menu_h.h"
#include "./gameplay/gameplay.h"

typedef struct button_script_s {
    const unsigned short id;
    void (*fc)();
}button_script_t;

typedef struct button_script_arr_s {
    const unsigned short id;
    button_script_t button_arr[12];
}button_script_arr_t;

typedef enum type {
    menu,
    menu_options,
    menu_how_to_play,
    in_game,
    game_option,
    inventory,
    in_combat,
    in_dungeon,
    in_pause,
    end_game,
    start_game,
    in_skill,
}type_e;

//Menu
void go_to_option(game_t *gm);
void go_to_how_to_play(game_t *gm);
void exit_game(game_t *gm);
void change_to_gameplay(game_t *gm);
    //Option
void choose_fps(void);
void back_to_menu(game_t *gm);
void option(game_t *gm);
void how_to_play(game_t *gm);
void small_window_size(game_t *gm);
void medium_window_size(game_t *gm);
void high_window_size(game_t *gm);
void low_fps(game_t *gm, menu_t *mn);
void medium_fps(game_t *gm, menu_t *mn);
void high_fps(game_t *gm, menu_t *mn);

//Game
    //Inventory
void interact_inventory(game_t *gm, play_t *game);
void interact_item(game_t *gm, play_t *game);
void interact_equipped_item(game_t *gm, play_t *game);
void detect_body_part(game_t *gm, play_t *game);
    //Combat
void attack_mobs(game_t *gm, play_t *game);
void attack_mobs_aoe(game_t *gm, play_t *game);
void drink_potion(game_t *gm, play_t *game);
void close_inventory(game_t *gm);
void save_game(game_t *gm, play_t *game);
void stop_pause(game_t *gm);
void respawn(game_t *gm, play_t *game);
void return_to_menu(game_t *gm);
void reset_dungeon(game_t *gm, play_t *game);
void sound_off(game_t *gm, menu_t *mn);

static const button_script_arr_t buttons_arr[] = {
    {
        menu, {
            {0, change_to_gameplay},
            {1, how_to_play},
            {2, option},
            {3, exit_game}
        }},
    {
        menu_options, {
            {0, back_to_menu},
            {1, choose_fps},
            {2, interact_inventory},
            {3, option},
            {4, small_window_size},
            {5, medium_window_size},
            {6, high_window_size},
            {7, low_fps},
            {8, medium_fps},
            {9, high_fps},
            {10, sound_off},
            {11, exit_game}
        }},
    {
        menu_how_to_play, {
            {0, back_to_menu},
        }},
    {
        in_game, {
    }},
    {
        game_option, {
    }},
    {
        inventory, {
            { 0, interact_inventory },
            { 1, interact_item },
            { 2, detect_body_part },
            { 3, interact_equipped_item },
            { 4, close_inventory }
        }},
    {
        in_combat, {
            { 0, attack_mobs },
            { 1, drink_potion },
            { 2, attack_mobs_aoe }
    }},
    {
        in_dungeon, {}
    },
    {
        in_pause, {
            { 0, stop_pause },
            { 1, save_game },
            { 2, respawn },
            { 3, return_to_menu },
            { 4, reset_dungeon }
        }
    }
};

#endif /* !BUTTON_H_ */
