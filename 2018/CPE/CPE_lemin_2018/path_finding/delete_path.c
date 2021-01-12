/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** delete_path.c
*/

#include "utils_lem_in.h"

void delete_first_node(ll_node_t *list_node, node_t *node)
{
    list_node->start = list_node->start->next;
    list_node->start->previous = NULL;
    node->next = NULL;
    node->previous = NULL;
    node = NULL;
}

void delete_last_node(ll_node_t *list_node, node_t *node)
{
    list_node->end = node->previous;
    list_node->end->next = NULL;
    node->next = NULL;
    node->previous = NULL;
    node = NULL;
}

void delete_node(ll_node_t *list_node, node_t *node)
{
    if (list_node->size == 1) {
    } else if (list_node->start == node) {
        delete_first_node(list_node, node);
    } else if (list_node->end == node) {
        delete_last_node(list_node, node);
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        node->next = NULL;
        node->previous = NULL;
        node = NULL;
    }
    list_node->size -= 1;
}

void check_list_node(box_t *tmp_box, vertex_t *temp_vert)
{
    for (node_t *temp_node = temp_vert->list_node->start; temp_node != NULL;
    temp_node = temp_node->next)
    {
        if (str_n_comp(temp_node->ID_node, tmp_box->ID_box,
        my_strlen(tmp_box->ID_box)) == 1)
        {
            delete_node(temp_vert->list_node, temp_node);
        }
    }
}

void delete_path(graph_t *graph, ll_box_t *list_box)
{
    for (box_t *tmp_box = list_box->start->next; tmp_box->next != NULL;
    tmp_box = tmp_box->next)
    {
        for (vertex_t *temp_vert = graph->list_vertex; temp_vert != NULL;
        temp_vert = temp_vert->next)
        {
            check_list_node(tmp_box, temp_vert);
        }
    }
}