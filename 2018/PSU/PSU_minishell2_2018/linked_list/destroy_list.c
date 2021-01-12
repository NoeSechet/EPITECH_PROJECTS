/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** destroy_list.c
*/

#include "utils_mini2.h"

void destroy_list(list_t *list)
{
    while (list->length > 1)
        pop_element_at(list, list->length);
}