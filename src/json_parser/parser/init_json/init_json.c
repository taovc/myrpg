/*
** EPITECH PROJECT, 2021
** init_json
** File description:
** Init a json
*/

#include "gamesys.h"
#include "my.h"

void get_json_spritesheet(json_t *parser, sfIntRect *rect)
{
    if (my_strncmp(((json_t *)parser->data[0])->id, "height", 6) == 0)
        (*rect).height = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "width", 5) == 0)
        (*rect).width = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "top", 3) == 0)
        (*rect).top = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "left", 4) == 0)
        (*rect).left = ((json_t *)parser->data[0])->data[0];
}

void get_json_pos(json_t *parser, sfVector2f *pos)
{
    int posx = -1;
    int posy = -1;

    if (my_strncmp(((json_t *)parser->data[0])->id, "posx", 4) == 0)
        posx = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "posy", 4) == 0)
        posy = ((json_t *)parser->data[0])->data[0];
    if (pos->x == 0 && posx != -1)
        (*pos).x = posx;
    if (pos->y == 0 && posy != -1)
        (*pos).y = posy;
}

void get_json_increment(json_t *parser, sfVector2f *incre)
{
    int increx = -1;
    int increy = -1;

    if (my_strncmp(((json_t *)parser->data[0])->id, "incre_x", 7) == 0)
        increx = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "incre_y", 7) == 0)
        increy = ((json_t *)parser->data[0])->data[0];
    if (incre->x == 0 && increx != -1)
        (*incre).x = increx;
    if (incre->y == 0 && increy != -1)
        (*incre).y = increy;
}

void get_json_increment_limit(json_t *parser, sfVector2f *limit_incre)
{
    int increx = -1;
    int increy = -1;

    if (my_strncmp(((json_t *)parser->data[0])->id, "limit_increx", 12) == 0)
        increx = ((json_t *)parser->data[0])->data[0];
    if (my_strncmp(((json_t *)parser->data[0])->id, "limit_increy", 12) == 0)
        increy = ((json_t *)parser->data[0])->data[0];
    if (limit_incre->x == 0 && increx != -1)
        (*limit_incre).x = increx;
    if (limit_incre->y == 0 && increy != -1)
        (*limit_incre).y = increy;
}

sfTexture *get_json_texture(json_t *parser, int *text)
{
    sfTexture *texture;

    if (my_strncmp(((json_t *)parser->data[0])->id, "texture", 7) == 0) {
        texture =
        sfTexture_createFromFile(((json_t *)parser->data[0])->data[0], NULL);
        *text = 1;
        return texture;
    }
    return NULL;
}