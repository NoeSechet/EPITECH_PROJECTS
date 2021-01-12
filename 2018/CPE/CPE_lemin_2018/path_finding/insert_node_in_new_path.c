/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** insert_node_in_new_path.c
*/

#include "utils_lem_in.h"

box_t *create_new_box(char *ID_node)
{
    box_t *box = malloc(sizeof(box_t));

    box->ID_ant = 0;
    box->ID_box = ID_node;
    box->role = lambda;
    box->status = available;
    box->next = NULL;
    box->previous = NULL;

    return (box);
}

void insert_node_in_new_path(char *ID_node, ll_box_t *list_box)
{
    box_t *new_box = create_new_box(ID_node);

    if (list_box->size == 0) {
        list_box->start = new_box;
        list_box->end = new_box;
    } else {
        list_box->end->next = new_box;
        new_box->previous = list_box->end;
        list_box->end = list_box->end->next;
    }
    list_box->size += 1;
}