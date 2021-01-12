/*
** EPITECH PROJECT, 2019
** com_exec.c
** File description:
** com_exec.c
*/

#include "utils_mini2.h"
#include "mini_command.h"
#include "bin_tree.h"

int com_exec(char **tab, list_t *list, bin_tree_t *bin_tree)
{
    (void)bin_tree;
    char **environ = convert_list_env(list);

    if (environ == NULL) {
        my_printf("%s: Command not found.\n", tab[0]);
        return (-1);
    }
    if (access(tab[0], X_OK) == 0) {
        fork_exec(tab[0], tab, environ, bin_tree);
    }
    return (0);
}