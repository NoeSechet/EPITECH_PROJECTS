/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** exec_setenv
*/

#include "mysh.h"

char *concat_elem(char *elem, char *value)
{
    int i = 0;

    for (; elem[i] != '='; i++);
    i += 1;
    elem[i] = '\0';
    elem = my_strcat(elem, value);
    return (elem);
}

int do_setenv_2(list_t *list, char *name, char *value)
{
    elem_t *elem = list->start;
    int size = 0;

    while (elem) {
        if (my_strncmp(elem->data, name, strlen(name)) == 0) {
            size = strlen(elem->data);
            change_value(elem->data, value, list, size);
            return (0);
        }
        elem = elem->next;
    }
    name = my_strcat(name, "=");
    name = my_strcat(name, value);
    push_back_haroun(list, name);
    return (0);
}
