/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** print_graph.c
*/

#include "utils_lem_in.h"

void print_graph(graph_t *graph)
{
    my_printf("- - - - - -\n\n");
    for (vertex_t *tmp1 = graph->list_vertex; tmp1 != NULL;
    tmp1 = tmp1->next) {
        my_printf("- Vertex[%s]\n\n", tmp1->ID_vertex);
        for (node_t *tmp2 = tmp1->list_node->start; tmp2 != NULL;
        tmp2 = tmp2->next)
            my_printf("Node[%s]\n", tmp2->ID_node);
        my_printf("\n");
    }
    my_printf("- - - - - -\n");
}