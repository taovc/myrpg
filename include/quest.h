/*
** EPITECH PROJECT, 2021
** quest
** File description:
** Quest header file
*/

#ifndef QUEST_H_
#define QUEST_H_

#include <SFML/Graphics.h>

enum pnj_e {
    pnj1,
    pnj2
};

enum mobs_e {
    mobs1,
    mobs2
};

enum item_e {
    item1,
    item2
};

enum objective_e {
    kill,
    talk,
    collect,
    give
};

typedef struct quest_s {
    int to_kill;
    int who;
    int objective;
    int to_who;
    sfText *descrip;
}quest_t;

#endif /* !QUEST_H_ */
