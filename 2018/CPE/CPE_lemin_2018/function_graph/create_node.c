/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** create_node.c
*/

#include "utils_lem_in.h"

node_t *create_node(char *str)
{
    node_t *node = malloc(sizeof(node_t));

    node->ID_node = str;
    node->next = NULL;
    node->previous = NULL;
    return (node);
}