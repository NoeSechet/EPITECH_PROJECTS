/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include "utils_lem_in.h"

vertex_t *init_list_vertex(void)
{
    vertex_t *list_vertex = malloc(sizeof(vertex_t));

    list_vertex->ID_vertex = NULL;
    list_vertex->list_node = NULL;
    list_vertex->next = NULL;
    list_vertex->role = 0;

    return (list_vertex);
}

graph_t *init_graph(void)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->nb_ants = 0;
    graph->nb_vertices = 0;
    graph->list_vertex = init_list_vertex();

    return (graph);
}