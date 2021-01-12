/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** fill_list_path.c
*/

#include "utils_lem_in.h"

int unknown_node(char *ID_node, ll_box_t *list_box)
{
    for (box_t *temp_box = list_box->start; temp_box != NULL;
    temp_box = temp_box->next) {
        if (str_n_comp(temp_box->ID_box, ID_node, my_strlen(ID_node)) == 1) {
            return (0);
        }
    }
    return (1);
}

ll_box_t *find_best_path(graph_t *graph, ll_box_t *list_box, char *ID_in,
char *ID_out)
{
    vertex_t *target = get_vertex(graph, ID_in);

    if (str_n_comp(ID_in, ID_out, my_strlen(ID_out)) == 1) {
        return (list_box);
    }
    for (node_t *temp_node = target->list_node->start; temp_node != NULL;
    temp_node = temp_node->next) {
        if (unknown_node(temp_node->ID_node, list_box) == 1) {
            insert_node_in_new_path(temp_node->ID_node, list_box);
            return (find_best_path(graph, list_box, temp_node->ID_node,
            ID_out));
        }
    }
    return (NULL);
}

int fill_list_path(graph_t *graph, ll_path_t *list_path)
{
    vertex_t *in = get_start(graph);
    vertex_t *out = get_exit(graph);
    ll_box_t *list_box = NULL;

    for (; in->list_node->size > 0; ) {
        list_box = init_list_box();
        insert_node_in_new_path(in->ID_vertex, list_box);
        if (find_best_path(graph, list_box, in->ID_vertex,
        out->ID_vertex) == NULL)
            return (-1);
        insert_new_path(list_path, list_box);
        delete_path(graph, list_box);
        if (list_box->size == 2) {
            list_path = init_list_path();
            insert_new_path(list_path, list_box);
            break;
        }
    }
    return (1);
}