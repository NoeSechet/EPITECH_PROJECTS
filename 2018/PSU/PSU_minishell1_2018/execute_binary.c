/*
** EPITECH PROJECT, 2019
** execute_binary.c
** File description:
** execute_binary.c
*/

#include "include/utils.h"

void check_status_error(int *sig)
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
}

int fork_exec(char *exec, char **tab, char **environ)
{
    int fork_ret =  fork();
    int sig = 0;

    if (fork_ret) {
        waitpid(fork_ret, &sig, 0);
        check_status_error(&sig);
    }
    if (fork_ret == 0) {
        execve(exec, tab, environ);
    }
    return (0);
}

int execute_binary(char **tab, char **environ, char *path)
{
    if (environ == NULL) {
        my_printf("%s: Command not found.\n", tab[0]);
        return (-1);
    }
    fork_exec(fusion(fusion(path, "/"), tab[0]), tab, environ);
    return (0);
}