/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** init_list_path.c
*/

#include "utils_lem_in.h"

ll_box_t *init_list_box(void)
{
    ll_box_t *list_box = malloc(sizeof(ll_box_t));

    list_box->size = 0;
    list_box->start = NULL;
    list_box->end = NULL;


    return (list_box);
}

path_t *init_path(void)
{
    path_t *list_path = malloc(sizeof(path_t));

    list_path->list_box = init_list_box();
    list_path->next = NULL;

    return (list_path);
}

ll_path_t *init_list_path(void)
{
    ll_path_t *list_path = malloc(sizeof(ll_path_t));

    list_path->nb_path = 0;
    list_path->start = NULL;
    list_path->end = NULL;

    return (list_path);
}