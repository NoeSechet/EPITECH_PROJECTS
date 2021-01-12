/*
** EPITECH PROJECT, 2019
** com_env.c
** File description:
** com_env.c
*/

#include "utils_mini2.h"
#include "mini_command.h"
#include "bin_tree.h"

int com_env(char **tab, list_t *list, bin_tree_t *bin_tree)
{
    (void)tab;
    int fork_ret = 0;
    int sig = 0;

    if ((fork_ret = fork()) == -1)
        return (-1);
    if (fork_ret == 0) {
        close(bin_tree->fd[0]);
        dup2(bin_tree->fd[1], 1);
        for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
            my_printf("%s\n", temp->str);
    }
    if (fork_ret) {
        waitpid(fork_ret, &sig, 0);
        bin_tree->fd[0] != 0 ? close(bin_tree->fd[0]) : 0;
        bin_tree->fd[1] != 1 ? close(bin_tree->fd[1]) : 0;
        check_status_error(&sig);
    }
    return (0);
}