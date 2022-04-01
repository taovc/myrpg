/*
** EPITECH PROJECT, 2021
** item_struct
** File description:
** Item structure
*/

#ifndef ITEM_STRUCT_H_
#define ITEM_STRUCT_H_

typedef struct item_s {
    char *texture;
    int attack;
    int hp;
    int def;
    int type;
}item_t;

#endif /* !ITEM_STRUCT_H_ */
