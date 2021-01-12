/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** insert_new_path.c
*/

#include "utils_lem_in.h"

void insert_new_path(ll_path_t *list_path, ll_box_t *list_box)
{
    path_t *new_path = init_path();

    list_box->start->role = start;
    list_box->end->role = end;

    new_path->list_box = list_box;

    if (list_path->nb_path == 0) {
        list_path->start = new_path;
        list_path->end = new_path;
    } else {
        list_path->end->next = new_path;
        new_path->previous = list_path->end;
        list_path->end = new_path;
    }
    list_path->nb_path += 1;
}