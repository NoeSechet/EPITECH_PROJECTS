/*
** EPITECH PROJECT, 2019
** execute_binary.c
** File description:
** execute_binary.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int check_status_error(int *sig)
{
    int segfault_val = 0;

    if (WIFSIGNALED(*sig) == 1) {
        segfault_val = WTERMSIG(*sig);
        switch (segfault_val)
        {
            case 6: my_printf("Abort"); break;
            case 8: my_printf("Floating exception"); break;
            case 11: my_printf("Segmentation fault"); break;
            default:
                break;
        }
        (WCOREDUMP(*sig)) ? my_printf(" (core dumped)") : 0;
        my_putchar('\n');
    }
    return (*sig);
}

int fork_exec(char *exec, char **tab, char **environ, bin_tree_t *bin_tree)
{
    int fork_ret = 0;
    int sig = 0;
    int fd[2];

    fd[0] = dup(0);
    fd[1] = dup(1);

    if ((fork_ret = fork()) == -1)
        return (-1);
    if (fork_ret == 0) {
        dup2(bin_tree->fd[0], 0);
        dup2(bin_tree->fd[1], 1);
        execve(exec, tab, environ);
        if (errno == ENOEXEC)
            my_printf("%s: Exec format error. Wrong Architecture.\n", exec);
        exit(84);
    }
    if (fork_ret) {
        waitpid(fork_ret, &sig, 0);
        close(bin_tree->fd[0]);
        close(bin_tree->fd[1]);
        dup2(fd[0], 0);
        dup2(fd[1], 1);
    }
    return (check_status_error(&sig));
}

int execute_binary(char **tab, char *path, list_t *list, bin_tree_t *bin_tree)
{
    char **environ = convert_list_env(list);

    if (environ == NULL) {
        my_printf("%s: Command not found.\n", tab[0]);
        return (-1);
    }
    fork_exec(fusion(fusion(path, "/"), tab[0]), tab, environ, bin_tree);
    return (0);
}