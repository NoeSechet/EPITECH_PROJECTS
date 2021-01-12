/*
** EPITECH PROJECT, 2019
** destroyer.c
** File description:
** destroyer.c
*/

#include "utils_mini2.h"

void destroy_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        free(tab[i]);
    }
}