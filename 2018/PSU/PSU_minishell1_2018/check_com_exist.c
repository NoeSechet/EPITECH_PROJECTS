/*
** EPITECH PROJECT, 2019
** check_com_exist.c
** File description:
** check_com_exist.c
*/

#include "include/utils.h"

char *check_com_exist(char **tab, list_t *list, char **environ)
{
    char **path_tab = NULL;

    if ((path_tab = special_str_tab(get_environment_val("PATH", list), ':'))
    == NULL) {
        my_printf("%s: Command not found.\n", tab[0]);
        return (NULL);
    }
    if (access(tab[0], X_OK) == 0) {
        fork_exec(tab[0], tab, environ);
        return (NULL);
    }
    for (int i = 0; path_tab[i] != NULL; i += 1) {
        if (access(fusion(fusion(path_tab[i], "/"), tab[0]), X_OK) == 0)
            return (path_tab[i]);
    }
    my_printf("%s: Command not found.\n", tab[0]);
    return (NULL);
}