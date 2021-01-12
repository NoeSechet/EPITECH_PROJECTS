/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** complete_bin_tree.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

static const tree_operator_t operator[] = {
    {";", &semi_col_exec},
    {">>", &d_redic_right_exec},
    {"<<", &d_redic_left_exec},
    {">", &redic_right_exec},
    {"<", &redic_left_exec},
    {"|", &pipe_exec},
    {NULL, NULL}
};

int complete_bin_tree(bin_tree_t *bin_tree, char *input)
{
    char **sem_col_branch = NULL;

    for (int i = 0; operator[i].op != NULL; i += 1) {
        if ((sem_col_branch = opera_sep(input, operator[i].op)) != NULL) {
            add_new_opera_node(bin_tree, sem_col_branch, operator[i].op);
            complete_bin_tree(bin_tree->left, bin_tree->left->command_parser);
            complete_bin_tree(bin_tree->right,
                bin_tree->right->command_parser);
            return (0);
        }
    }
    return (1);
}