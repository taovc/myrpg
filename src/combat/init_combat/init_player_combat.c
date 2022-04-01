/*
** EPITECH PROJECT, 2021
** init_player_combat
** File description:
** Init the player in combat
*/

#include "gamesys.h"
#include "./gameplay/gameplay_struct.h"
#include "my.h"
#include <stdlib.h>

static void insert_player_zero(player_t *player)
{
    player->incre.x = 0;
    player->incre.y = 0;
    player->incre_limit.x = 0;
    player->incre_limit.y = 0;
    player->rect.height = 0;
    player->rect.left = 0;
    player->rect.top = 0;
    player->rect.width = 0;
    player->player = NULL;
    player->texture = NULL;
}

static void insert_player_sprite(player_t *player)
{
    if (player->texture) {
        player->player = sfSprite_create();
        sfSprite_setTexture(player->player, player->texture, sfTrue);
        sfSprite_setTextureRect(player->player, player->rect);
    }
}

void insert_player(player_t *player, json_t *parser)
{
    for (int j = 0, text = 0; parser->data[j] != NULL; j++) {
        get_json_spritesheet(parser->data[j], &player->rect);
        get_json_increment_limit(parser->data[j], &player->incre_limit);
        get_json_increment(parser->data[j], &player->incre);
        if (text == 0)
            player->texture = get_json_texture(parser->data[j], &text);
    }
    insert_player_sprite(player);
}

void init_combat_struct(combat_t *combat)
{
    json_t *parser = json_parser("./config_files/player.json");

    combat->in_combat = 0;
    combat->player = malloc(sizeof(player_t));
    for (int i = 0; parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)parser->data[i])->id,
            "player", 6) == 0) {
            insert_player_zero(combat->player);
            insert_player(combat->player, parser->data[i]);
            break;
        }
    }
}
