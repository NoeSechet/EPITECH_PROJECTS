/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_redir
*/

#include "mysh.h"

int exec_left_redirection(tree_t *tree, main_list_t *main)
{
    char *file = (tree->right->command[0] == ' ') ?
        my_strdup(tree->right->command + 1) :
        my_strdup(tree->right->command);
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        free(file);
        close(fd);
        my_printf("%s: No such file or directory.\n", file);
        return (1);
    } else {
        tree->left->fd[0] = fd;
        do_execution(tree->left, main);
    }
    free(file);
    close(fd);
    return (0);
}

int exec_right_redirection(tree_t *tree, main_list_t *main)
{
    char *file = (tree->right->command[0] == ' ') ?
        my_strdup(tree->right->command + 1) :
        my_strdup(tree->right->command);
    int fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 00777);

    tree->left->fd[1] = fd;
    free(file);
    do_execution(tree->left, main);
    close(fd);
    return (0);
}
