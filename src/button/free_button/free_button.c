/*
** EPITECH PROJECT, 2021
** free_button
** File description:
** Free the buttons
*/

#include "./button/button.h"
#include <stdio.h>
#include <stdlib.h>

void free_button(button_t **button)
{
    for (int j = 0; button[j] != NULL; j++) {
        if (button[j]->button_text != NULL) {
            sfTexture_destroy(button[j]->button_text);
        }
        if (button[j]->button_mouseover != NULL) {
            sfTexture_destroy(button[j]->button_mouseover);
        }
        if (button[j]->button != NULL) {
            sfSprite_destroy(button[j]->button);
        }
        free(button[j]);
    }
    free(button);
}
