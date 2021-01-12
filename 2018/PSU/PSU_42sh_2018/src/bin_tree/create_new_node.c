/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** create_new_node.c
*/

#include "lib.h"
#include "struct_tree.h"

int *create_fd(void)
{
    int *fd = malloc(sizeof(int) * 2);

    fd[0] = 0;
    fd[1] = 1;
    return (fd);
}

tree_t *create_new_node(char *opera_node)
{
    tree_t *bin_tree = malloc(sizeof(tree_t));

    bin_tree->fd = create_fd();
    bin_tree->opera = NULL;
    bin_tree->command = strclean_spe(opera_node, ' ', 0);
    bin_tree->left = NULL;
    bin_tree->right = NULL;

    return (bin_tree);
}