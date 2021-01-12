/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec_double execution
*/

#include "mysh.h"

int exec_double_redirection_left(tree_t *tree, main_list_t *main)
{
    char *str = NULL;
    char *cmd = (tree->right->command[0] == ' ') ?
        my_strdup(tree->right->command + 1) : my_strdup(tree->right->command);
    int fd = open(".left_redir", O_RDONLY | O_TRUNC);

    while (1) {
        (isatty(0)) ? my_printf("? ") : 0;
        str = get_next_line(0);
        if (my_strcmp(str, cmd) == 0)
            break;
        else
            write(fd, str, strlen(str));
        free(str);
    }
    free_vars(cmd, str);
    tree->left->fd[0] = fd;
    do_execution(tree->left, main);
    close(fd);
    return (0);
}

int exec_double_redirection_right(tree_t *tree, main_list_t *main)
{
    char *file = (tree->right->command[0] == ' ') ?
        my_strdup(tree->right->command + 1) :
        my_strdup(tree->right->command);
    int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 00777);

    tree->left->fd[1] = fd;
    do_execution(tree->left, main);
    close(fd);
    free(file);
    return (0);
}
