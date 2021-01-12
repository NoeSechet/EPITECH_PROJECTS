/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** pipe_exec.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int pipe_exec(bin_tree_t *pipe_node, list_t *list)
{
    int pid = 0;
    int copy_fd[2];
    int sig = 0;

    pipe_node->left->fd[0] = pipe_node->fd[0];
    pipe_node->right->fd[1] = pipe_node->fd[1];
    if ((pipe(copy_fd)) == -1) return (-1);
    pipe_node->left->fd[1] = copy_fd[1];
    pipe_node->right->fd[0] = copy_fd[0];
    if ((pid = fork()) == -1)
        return (-1);
    if (pid == 0) {
        close(copy_fd[0]);
        execute_bin_tree(pipe_node->left, list);
    } else {
        close(copy_fd[1]);
        execute_bin_tree(pipe_node->right, list);
        waitpid(pid, &sig, 0);
    }
    return (0);
}