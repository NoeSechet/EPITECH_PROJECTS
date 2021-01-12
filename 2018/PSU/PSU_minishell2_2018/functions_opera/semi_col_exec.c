/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** semi_col_exec.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int semi_col_exec(bin_tree_t *node, list_t *list)
{
    execute_bin_tree(node->left, list);
    execute_bin_tree(node->right, list);
    return (0);
}