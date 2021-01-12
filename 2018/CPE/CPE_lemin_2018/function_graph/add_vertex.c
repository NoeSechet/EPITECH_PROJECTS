/*
** EPITECH PROJECT, 2019
** add_vertex
** File description:
** add_vertex
*/

#include "utils_lem_in.h"

ll_node_t *init_list_node(void)
{
    ll_node_t *new_list = malloc(sizeof(ll_node_t));

    new_list->size = 0;
    new_list->start = NULL;
    new_list->end = NULL;

    return (new_list);
}

vertex_t *create_vertex(char *str, role_t role)
{
    vertex_t *new_vertex = malloc(sizeof(vertex_t));

    new_vertex->ID_vertex = str;
    new_vertex->role = role;
    new_vertex->list_node = init_list_node();
    new_vertex->next = NULL;

    return (new_vertex);
}

void add_vertex(graph_t *graph, char *str, role_t role)
{
    vertex_t *vertex = create_vertex(str, role);

    if (graph->nb_vertices == 0)
        graph->list_vertex = vertex;
    else {
        vertex->next = graph->list_vertex;
        graph->list_vertex = vertex;
    }
    graph->nb_vertices += 1;
}