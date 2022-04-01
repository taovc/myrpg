/*
** EPITECH PROJECT, 2020
** gamesys
** File description:
** Contains all the functions for the gamesys
*/

#if !defined(SCENE_H)
#define SCENE_H

#include <SFML/Graphics.h>
#include "mysfmllib.h"

typedef struct parti_t {
    const unsigned short id;
    void (*fc)();
} parti_t;

typedef enum parti_e {
    exit_parti,
    menu_parti,
    gameplay_parti,
    over_parti,
    pause_parti
} parti_e;

void my_menu();
void my_gameplay();

static const parti_t ALL_parti[] = {
    {exit_parti, NULL},
    {menu_parti, my_menu},
    {gameplay_parti, my_gameplay},
    {over_parti, NULL},
    {pause_parti, NULL}
};

static const int NB_parti = sizeof(ALL_parti) / sizeof(parti_t);

#endif // SCENE_H