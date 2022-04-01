/*
** EPITECH PROJECT, 2021
** create_text
** File description:
** Create text
*/

#include "gamesys.h"
#include "./gameplay/gameplay.h"

sfText *creat_text_as_file(char *file, char *str, int x, int y)
{
    sfFont *fon = sfFont_createFromFile(file);
    sfText *txt = sfText_create();

    sfText_setString(txt, str);
    sfText_setFont(txt, fon);
    sfText_setPosition(txt, (sfVector2f){x, y});
    sfText_setCharacterSize(txt, 40);
    sfText_setColor(txt, sfCyan);
    return txt;
}

sfSprite *create_text_sp(char *str, int x, int y)
{
    sfVector2f bollpos = {x, y};
    sfTexture *textures;
    sfSprite *sprites = NULL;

    textures = sfTexture_createFromFile(str, NULL);
    sprites = sfSprite_create();
    sfSprite_setTexture(sprites, textures, sfTrue);
    sfSprite_setPosition(sprites, bollpos);
    return (sprites);
}
