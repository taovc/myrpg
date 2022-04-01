/*
** EPITECH PROJECT, 2021
** pnj
** File description:
** Pnj headerfile
*/

#ifndef NPC_ENTITIES_H_
#define NPC_ENTITIES_H_

#include <SFML/Graphics.h>

enum npc_id {
    random_npc,
    mom,
    doggy
};

enum zone {
    village,
    house,
    dungeon
};

typedef struct npc_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfText *dialog;
    sfFont *font;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f incre;
    sfVector2f incre_limit;
    int npc_id;
    int zone;
}npc_t;

#endif /* !NPC_ENTITIES_H_ */
