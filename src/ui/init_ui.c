/*
** EPITECH PROJECT, 2021
** init_ui
** File description:
** Init the ui
*/

#include "gamesys.h"
#include <stdlib.h>
#include "my.h"

static void init_ui_sprite(ui_t *ui, sfVector2i pos)
{
    sfVector2f sprite_pos = {pos.x, pos.y};

    if (ui->ui_texture) {
        ui->can_draw = DROW_TOUCH;
        ui->ui_sprite = sfSprite_create();
        sfSprite_setTexture(ui->ui_sprite, ui->ui_texture, sfTrue);
        sfSprite_setPosition(ui->ui_sprite, sprite_pos);
    }
}

static void get_ui_texture(ui_t *ui, json_t *ui_parser)
{
    sfVector2i pos = {0, 0};

    for (int i = 0; ui_parser->data[i]; i++) {
        if (my_strncmp(((json_t *)ui_parser->data[i])->id, "texture", 7) == 0)
            ui->ui_texture = sfTexture_createFromFile(((json_t *)
            ((json_t *)ui_parser->data[i])->data[0])->data[0], NULL);
        if (my_strncmp(((json_t *)ui_parser->data[i])->id, "type", 4) == 0)
            ui->type = ((json_t *)
            ((json_t *)ui_parser->data[i])->data[0])->data[0];
        if (my_strncmp(((json_t *)ui_parser->data[i])->id, "posx", 4) == 0)
            pos.x = ((json_t *)
            ((json_t *)ui_parser->data[i])->data[0])->data[0];
        if (my_strncmp(((json_t *)ui_parser->data[i])->id, "posy", 4) == 0)
            pos.y = ((json_t *)
            ((json_t *)ui_parser->data[i])->data[0])->data[0];
    }
    init_ui_sprite(ui, pos);
}

static void insert_ui(ui_t **ui, json_t *ui_parser)
{
    for (int i = 0, j = 0; ui_parser->data[i] != NULL; i++) {
        if (my_strncmp(((json_t *)ui_parser->data[i])->id,
            "ui", 2) == 0) {
            ui[j] = malloc(sizeof(ui_t));
            get_ui_texture(ui[j], ui_parser->data[i]);
            j++;
        }
    }
}

ui_t **init_ui(char *filepath)
{
    json_t *ui_parser = json_parser(filepath);
    int len = get_json_args(ui_parser, "ui", 2);
    ui_t **ui = malloc(sizeof(ui_t *) * (len + 1));

    ui[len] = NULL;
    insert_ui(ui, ui_parser);
    free_parser(ui_parser);
    free(ui_parser->data);
    free(ui_parser);
    return ui;
}
