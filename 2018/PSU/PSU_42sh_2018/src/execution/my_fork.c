/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_fork
*/

#include "mysh.h"

void check_exec(char **comand, char **env)
{
    if (execve(comand[0], comand, env) != 0) {
        my_printf("%s: Exec format error. Wrong Architecture.\n",
        comand[0]);
        exit(1);
    }
}

int secur_fd(int *fd)
{
    fd[0] = dup(0);
    fd[1] = dup(1);
    if (fd[0] == -1 || fd[1] == -1)
        return (1);
    return (0);
}

int my_fork(char **comand, tree_t *tree, char **env)
{
    int my_fork = 0;
    int status = 0;
    int fd[2];

    secur_fd(fd);
    my_fork = fork();
    if (my_fork == 0) {
        dup2(tree->fd[0], 0);
        dup2(tree->fd[1], 1);
        check_exec(comand, env);
    } else {
        waitpid(my_fork, &status, 0);
        close(tree->fd[0]);
        close(tree->fd[1]);
        dup2(fd[0], 0);
        dup2(fd[1], 1);
    }
    return (check_signal(status));
}