/*
** EPITECH PROJECT, 2020
** menu
** File description:
** Contains all the functions for the menu
*/

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "./gamesystem/gamesys_struct.h"
#include "./gameplay/gameplay_struct.h"
#include "./gameplay/mobs_struct.h"
#include "music.h"
#include <stdio.h>

//Start of program
npc_t **init_npc(char *filepath);
mob_list_t *init_mobs(char *filepath);
map_t *init_djmaps(char *filepath);
void init_combat_struct(combat_t *combat);
void insert_npc(json_t *parser, npc_t *npc);
void insert_mobs(mobs_t *mob, json_t *parser);
music_t *init_combat_music(void);
sfMusic *music_run(void);
int play_sound(play_t *snd_music);
void init_game_dungeon(play_t *game, game_t *gm);
inventory_stat_t *init_inventory_stat(buttons_t *button,
player_stat_t *p_stat);
void init_skill(game_t *gm, play_t *game, save_t *save);

//Move in map
void main_map_evnt(game_t *gm, play_t *py);

//skill
void skill_tree_evnt(game_t *gm, play_t *py);

//Init Save
save_t *init_save(char *filepath);
player_stat_t *init_player_stat(save_t *save);
void init_inventory(game_t *gm, play_t *game, save_t *save);

//Save
void save_int(FILE *file, int value, int tab, char *id);
void save_arr(FILE *file, int *arr, int size, char *id);
void save_stat(play_t *game, FILE *file);
void save_inventory(play_t *game, FILE *file);
void save_dungeon_state(play_t *game, FILE *file);

//Event
void event_game(game_t *gm, play_t *game);
void dungeon_evnt(game_t *gm, play_t *py);

//Draw
void game_conditional_draw(game_t *gm, play_t *game);
void move_every_spritesheet(game_t *gm, play_t *game);
void move_combat_spritesheet(game_t *gm, combat_t *combat);
void draw_inventories(game_t *gm, play_t *game);
void draw_combat(game_t *gm, combat_t *combat);
void display_game(game_t *gm, play_t *game);
void draw_game(game_t *gm, play_t *game);

//Combat
void give_item(game_t *gm, play_t *game, int item_id);
void start_combat(game_t *gm, play_t *game);
void init_combat(play_t *game, game_t *gm, int nbr_mobs);
void set_target_pos(combat_t *combat);
void update_xp_bar(sfSprite *xp, int exp);
void update_hp_bar(sfSprite *hp_bar, int *hp, sfVector2f hp_took);
void random_encounter(game_t *gm, play_t *py);
    //Win condition
void gain_exp(play_t *game, int exp);
void respawn(game_t *gm, play_t *game);
void get_target(game_t *gm, play_t *game);
void get_new_target(combat_t *combat);
void loose(game_t *gm, play_t *game);
void win(game_t *gm, play_t *game);
int check_dead(game_t *gm, play_t *game);
    //Damage
void kill_mobs(game_t *gm, play_t *game, int target);
void take_damage_mobs(game_t *gm, play_t *game, int target);
void take_aoe_damage(game_t *gm, play_t *game, int target);
int take_damage_player(game_t *gm, play_t *game, int ted);
    //Animation
void dead_animation(game_t *gm, play_t *game);
void hit_animation(game_t *gm, play_t *game, sfVector2f pos);
int attack_player(game_t *gm, play_t *game, int ter);
void attack_animation(game_t *gm, play_t *game, attack_tmp_t *tmp);
void fallback_animation(game_t *gm, play_t *game, attack_tmp_t *tmp,
sfSprite *effect);
    //Reward
void reward(game_t *gm, play_t *game);

//Inventory
void throw(play_t *game, int item);
void unequip_item(game_t *gm, play_t *game, int part);
void equip(game_t *gm, play_t *game, int item);
void insert_item(inventory_t *inventory, int item_id, int item,
buttons_t *button);
void insert_equip_item(equipped_inventory_t *inventory, int item_id,
int item, buttons_t *button);
void search_last_item(inventory_t **inventory, game_t *gm);
void update_inv_stat(inventory_stat_t *stat, player_stat_t *p_stat);

//NPC
void move_npc_spritesheet(game_t *gm, play_t *game);

//End of program
int *construct_arr_from_inventory(play_t *game);
void free_inventory(all_inventory_t *inventories);
void free_ui(ui_t **ui);
void free_npc(npc_t **npc);
void free_mobs(mob_list_t *mobs);
void free_combat(combat_t *combat);
void free_combat_mobs(combat_t *combat);
void free_music(music_alone_t **music);

#endif /* !GAMEPLAY_H_ */
