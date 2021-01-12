/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** destroy_list.c
*/

#include "include_linked_list/linked_list.h"

void destroy_list(list_t *list)
{
    while (list->size > 1)
        pop_element_at(list, list->size);
}