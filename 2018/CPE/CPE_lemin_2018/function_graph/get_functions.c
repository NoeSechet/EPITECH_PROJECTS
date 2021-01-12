/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** get_start_end.c
*/

#include "utils_lem_in.h"

vertex_t *get_start(graph_t *graph)
{
    vertex_t *temp = NULL;

    for (temp = graph->list_vertex; temp->role != start
    && temp != NULL; temp = temp->next);
    return (temp);
}

vertex_t *get_exit(graph_t *graph)
{
    vertex_t *temp = NULL;

    for (temp = graph->list_vertex; temp->role != end
    && temp != NULL; temp = temp->next);
    return (temp);
}

vertex_t *get_vertex(graph_t *graph, char *ID_vertex)
{
    vertex_t *temp = NULL;

    for (temp = graph->list_vertex;
    str_n_comp(ID_vertex, temp->ID_vertex, my_strlen(temp->ID_vertex)) != 1;
    temp = temp->next);

    return (temp);
}