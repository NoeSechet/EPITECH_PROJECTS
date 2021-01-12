/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** free_vars_tabs.c
*/

#include <stdlib.h>

void free_vars(char *a, char *b)
{
    if (a != NULL)
        free(a);
    if (b != NULL)
        free(b);
}

void free_tabs(char **tab)
{
    if (!tab || !tab[0])
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}