/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** add_new_opera_node.c
*/

#include "lib.h"
#include "struct_tree.h"

int add_new_opera_node(tree_t *last_node, char **opera_node, char *opera)
{
    tree_t *new_node_left = create_new_node(opera_node[0]);
    tree_t *new_node_right = create_new_node(opera_node[1]);

    last_node->left = new_node_left;
    last_node->right = new_node_right;
    last_node->opera = opera;
    last_node->command = NULL;
    return (1);
}