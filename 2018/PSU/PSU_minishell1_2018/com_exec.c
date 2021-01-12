/*
** EPITECH PROJECT, 2019
** com_exec.c
** File description:
** com_exec.c
*/

#include "include/utils.h"

int com_exec(char **tab, list_t *list, char **environ)
{
    (void)list;

    if (environ == NULL) {
        my_printf("%s: Command not found.\n", tab[0]);
        return (-1);
    }

    if (access(tab[0], X_OK) == 0) {
        fork_exec(tab[0], tab, environ);
    }
    return (0);
}