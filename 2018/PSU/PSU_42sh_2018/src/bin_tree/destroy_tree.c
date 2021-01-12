/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** destroy_tree.c
*/

#include "struct_tree.h"
#include "lib.h"

void destroy_tree(tree_t *tree)
{
    if (tree == NULL)
        return;
    if (tree->left != NULL) {
        destroy_tree(tree->left);
    }
    if (tree->right != NULL) {
        destroy_tree(tree->right);
    }
    free(tree->fd);
    free(tree);
}