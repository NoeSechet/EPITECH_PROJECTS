/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** print_bin_tree.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

void print_bin_tree(bin_tree_t *bin_tree)
{
    if (bin_tree->left != NULL) {
        print_bin_tree(bin_tree->left);
    }
    if (bin_tree->right != NULL) {
        print_bin_tree(bin_tree->right);
    }
    my_printf("%s\n", bin_tree->command_parser);
}