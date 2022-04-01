/*
** EPITECH PROJECT, 2021
** button
** File description:
** Button header file
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "parser.h"
#include "button_s.h"

typedef struct buttons_s {
    button_t **buttons;
    int type;
}buttons_t;

void free_button(button_t **button);
void insert_button(json_t *button_parser, button_t *button);

#endif /* !BUTTON_H_ */
