/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** redic_left_exec.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int redic_left_exec(bin_tree_t *redic_node, list_t *list)
{
    int pid = 0;
    int sig = 0;
    int fd_file = 0;

    if ((fd_file = open(redic_node->right->command_parser, O_RDONLY)) == -1)
        return (-1);
    redic_node->left->fd[0] = fd_file;
    redic_node->left->fd[1] = redic_node->fd[1];
    redic_node->right->fd[0] = fd_file;
    redic_node->right->fd[1] = redic_node->left->fd[1];
    execute_bin_tree(redic_node->left, list);
    close(fd_file);
    return (0);
}