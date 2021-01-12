/*
** EPITECH PROJECT, 2019
** destroyer.c
** File description:
** destroyer.c
*/

#include "include/utils.h"

void destroy_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        free(tab[i]);
    }
}

void destroy_list(list_t *list)
{
    while (list->length > 1)
        pop_element_at(list, list->length);
}