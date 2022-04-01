/*
** EPITECH PROJECT, 2021
** menu
** File description:
** menu
*/

#include "char/char.h"
#include "gamesys.h"
#include "./button/button_script.h"
#include "./gameplay/gameplay.h"
#include "./inventory/item.h"
#include "my.h"
#include "./inventory/inventory.h"
#include <stdlib.h>

static void free_game(play_t *game, save_t *save)
{
    for (map_t *cp; game->map; cp = game->map,
        game->map = game->map->next, free(cp));
    free_combat_mobs(game->combat);
    free_combat(game->combat);
    free(save->item_id);
    free(save);
    free_inventory(game->inventories);
    free_button(game->button->buttons);
    free(game->button);
    free_ui(game->ui);
    free_npc(game->npc);
    free_mobs(game->mobs_list);
    sfSprite_destroy(game->person);
    free_music(game->music->sound_eff);
    free(game->music);
    free(game);
}

static void init_about_save(play_t *game, game_t *gm, save_t *save)
{
    game->combat = malloc(sizeof(combat_t));
    game->combat->mobs = NULL;
    game->combat->player = NULL;
    game->selectioned_item = 0;
    game->music = init_combat_music();
    game->stats = init_player_stat(save);
    init_game_dungeon(game, gm);
    init_inventory(gm, game, save);
    init_combat_struct(game->combat);
    game->is_win = save->win;
    game->floor = save->floor;
    update_hp_bar(game->ui[2]->ui_sprite, &game->stats->hp,
        (sfVector2f){ game->stats->hp_max, 0});
    update_xp_bar(game->ui[9]->ui_sprite, game->stats->exp);
    init_skill(gm, game, save);
    if (game->snd_map)
        sfMusic_destroy(game->snd_map);
}

static void init_gameplay(play_t *game, game_t *gm, save_t *save)
{
    gm->zone = house;
    update_type(gm, in_game);
    game->snd_map = NULL;
    game->win_map = create_text_sp("./imgs/gameplay/NPC.png", -960, -220);
    game->npc = init_npc("./config_files/npc.json");
    game->ui = init_ui("./config_files/gameplay/game_ui.json");
    game->button = init_struct_button
        ("./config_files/gameplay/game_button.json");
    game->mobs_list = init_mobs("./config_files/mobs.json");
    game->combat = malloc(sizeof(combat_t));
    game->combat->mobs = NULL;
    game->combat->player = NULL;
    game->selectioned_item = 0;
    game->music = init_combat_music();
    game->stats = init_player_stat(save);
    init_about_save(game, gm, save);
}

void my_gameplay(game_t *gm)
{
    play_t *py = malloc(sizeof(play_t));
    save_t *save = init_save("save.json");

    sfRenderWindow_setMouseCursorVisible(gm->window, sfFalse);
    init_gameplay(py, gm, save);
    update_type(gm, in_game);
    py->snd_map = play_music("./sound/sound_map.ogg");
    while (sfRenderWindow_isOpen(gm->window)
        && gm->now_parti == gameplay_parti) {
        if (gm->type == in_dungeon)
            dungeon_evnt(gm, py);
        if (gm->type == in_game)
            main_map_evnt(gm, py);
        move_every_spritesheet(gm, py);
        display_game(gm, py);
        event_game(gm, py);
    }
    free_combat_mobs(py->combat);
    free_game(py, save);
}