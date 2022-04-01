/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** how to play change img
*/

#include "./menu/menu_struct.h"
#include <stdlib.h>
#include "mysfmllib.h"

htp_t *creat_node_img(char *str)
{
    htp_t *map = NULL;

    map = malloc(sizeof(htp_t));
    map->page = create_text_sp(str, 0, 0);
    map->next = NULL;
    map->pre = NULL;
    return map;
}

htp_t *insert_node_htp(htp_t *head, htp_t *data)
{
    htp_t *cp_head = head;

    for (; head->next; head = head->next);
    head->next = data;
    data->pre = head;
    return cp_head;
}

htp_t *creat_page_htp(void)
{
    htp_t *head = creat_node_img("./imgs/how_to_play/How_to_play.png");

    head = insert_node_htp(head, creat_node_img("./imgs/how_to_play/K.png"));
    head = insert_node_htp(head, creat_node_img("./imgs/how_to_play/H.png"));
    return head;
}