/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** redic_right_exec.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int redic_right_exec(bin_tree_t *redic_node, list_t *list)
{
    int pid = 0;
    int sig = 0;
    int fd_file = open(redic_node->right->command_parser, O_CREAT
    | O_WRONLY | O_TRUNC, 00664);

    redic_node->left->fd[0] = redic_node->fd[0];
    redic_node->left->fd[1] = fd_file;
    redic_node->right->fd[0] = fd_file;
    redic_node->right->fd[1] = redic_node->fd[1];

    execute_bin_tree(redic_node->left, list);
    close(fd_file);

    return (0);
}
