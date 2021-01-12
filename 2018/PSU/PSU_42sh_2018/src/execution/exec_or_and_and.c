/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** exec_or, exec_and
*/

#include "mysh.h"

int exec_and(tree_t *tree, main_list_t *main_list)
{
    if (do_execution(tree->left, main_list) == 0)
        do_execution(tree->right, main_list);
    return (0);
}

int exec_or(tree_t *tree, main_list_t *main_list)
{
    if (do_execution(tree->left, main_list) != 0)
        do_execution(tree->right, main_list);
    return (0);
}