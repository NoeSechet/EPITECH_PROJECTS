/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_realloc_2d
*/

#include "mysh.h"

char **my_realloc_2d(char **tab_to, int size)
{
    char **new_str = malloc(sizeof(char *) * (size + 1));
    int c = 0;

    if (tab_to == NULL || size < 1)
        return (NULL);
    for (; c != size && tab_to[c] != NULL; c++)
        new_str[c] = my_strdup(tab_to[c]);
    if (tab_to[c] == NULL)
        while (c < size)
            new_str[c++] = NULL;
    new_str[c] = NULL;
    free_tabs(tab_to);
    return (new_str);
}
