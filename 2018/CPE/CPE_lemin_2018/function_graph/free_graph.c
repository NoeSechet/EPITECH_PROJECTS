/*
** EPITECH PROJECT, 2019
** free
** File description:
** free
*/

#include "utils_lem_in.h"

void free_graph(graph_t *graph)
{
    node_t *tmp_node = NULL;
    vertex_t *tmp_vertex = NULL;

    for (vertex_t *vertex = graph->list_vertex; vertex != NULL;) {
        for (node_t *node = vertex->list_node->start; node != NULL;) {
                tmp_node = node;
                node = node->next;
                free(tmp_node);
        }
        tmp_vertex = vertex;
        vertex = vertex->next;
        free(tmp_vertex);
    }
    free(graph);
}