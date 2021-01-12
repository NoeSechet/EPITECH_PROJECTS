/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** my_unalias.c
*/

#include "mysh.h"

void unstock_alias(list_t *alias, char **input)
{
    if (alias->end == NULL || alias->start == NULL)
        return;
    for (int idx = 0; input[idx] != NULL; ++idx) {
        input[idx] = remove_quotes_alias(input[idx]);
        remove_if_aliased(alias, input[idx]);
    }
}

int my_unalias(main_list_t *main, tree_t *tree, char **input)
{
    int size = my_tablen(input);
    (void)tree;

    switch (size) {
        case 0: return (-1);
        case 1: write(2, "unalias: Too few arguments.\n", 29); break;
        default: unstock_alias(main->alias, (input + 1)); break;
    }
    return (0);
}
