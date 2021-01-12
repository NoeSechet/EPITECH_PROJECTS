/*
** EPITECH PROJECT, 2019
** edge
** File description:
** edge
*/

#include "utils_lem_in.h"

void insert_node(ll_node_t *list_node, node_t *new_node)
{
    if (list_node->size == 0) {
        list_node->start = new_node;
        list_node->end = new_node;
    } else {
        list_node->end->next = new_node;
        new_node->previous = list_node->end;
        list_node->end = new_node;
    }
    list_node->size += 1;
}

void check_start_end(vertex_t *temp, int *start_end_pres)
{
    if (temp->role != 2)
        *start_end_pres += 1;
}

int add_edge(graph_t *graph, char *node_1, char *node_2)
{
    node_t *new_node = NULL;
    int start_end_pres = 0;

    for (vertex_t *tmp = graph->list_vertex; tmp != NULL; tmp = tmp->next) {
        if (str_n_comp(node_1, tmp->ID_vertex, my_strlen(node_1)) == true) {
            new_node = create_node(node_2);
            insert_node(tmp->list_node, new_node);
            check_start_end(tmp, &start_end_pres);
        }
        if (str_n_comp(node_2, tmp->ID_vertex, my_strlen(node_2)) == true) {
            new_node = create_node(node_1);
            insert_node(tmp->list_node, new_node);
            check_start_end(tmp, &start_end_pres);
        }
    }
    return (start_end_pres);
}