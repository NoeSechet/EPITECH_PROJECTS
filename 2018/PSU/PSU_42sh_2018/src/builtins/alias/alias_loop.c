/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** alias_loop.c
*/

#include "mysh.h"

elem_t *get_elem_for_alias_loop(list_t *alias, char *input)
{
    elem_t *elem = NULL;

    for (elem = alias->start; elem != NULL; elem = elem->next) {
        if (my_strncmp(input, elem->data, my_strlen(input)) == 0)
            return (elem);
        if (elem->next == NULL)
            return (NULL);
    }
    return (NULL);
}

int check_alias_loop(list_t *alias, char *input, char *first_input)
{
    static int new_test = 0;
    elem_t *elem = NULL;
    char *new_input = NULL;
    int mal = 0;

    if (new_test != 0 && my_strcmp(input, first_input) == 0)
        return (1);
    if ((elem = get_elem_for_alias_loop(alias, input)) == NULL)
        return (0);
    for (; elem->data[mal] != '=' && elem->data[mal] != 0; ++mal);
    mal += 2;
    new_input = my_strdup(elem->data + mal);
    mal = 0;
    new_test = 1;
    if (check_alias_loop(alias, new_input, first_input) == 1)
        mal = 1;
    new_test = 0;
    free(new_input);
    return (mal);
}
