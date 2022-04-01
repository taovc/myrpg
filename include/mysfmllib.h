/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MYSFMLLIB_H_
#define MYSFMLLIB_H_

#include <SFML/Graphics.h>

sfSprite *create_text_sp(char *str, int x, int y);
sfRenderWindow *createmywindow(unsigned int width, unsigned int height);
void change_pos_souri(sfSprite *sp, sfRenderWindow *window);
void (*parti_now_used(unsigned short id));
sfText *creat_text_as_file(char *file, char *str, int x, int y);

#endif /* _!MYSFMLLIB_H_ */