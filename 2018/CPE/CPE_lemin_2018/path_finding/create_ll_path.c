/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** create_ll_path.c
*/

#include "utils_lem_in.h"

ll_path_t *create_list_path(graph_t *graph)
{
    ll_path_t *list_path = init_list_path();

    if (fill_list_path(graph, list_path) == -1)
        return (NULL);
    return (list_path);
}