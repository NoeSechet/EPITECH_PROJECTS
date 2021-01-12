/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** add_new_opera_node.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int add_new_opera_node(bin_tree_t *last_node, char **opera_node, char *opera)
{
    bin_tree_t *new_node_left = create_new_node(opera_node[0]);
    bin_tree_t *new_node_right = create_new_node(opera_node[1]);

    last_node->left = new_node_left;
    last_node->right = new_node_right;
    last_node->command_parser = opera;

    return (1);
}