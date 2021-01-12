/*
** EPITECH PROJECT, 2019
** new_list.c
** File description:
** new_list.c
*/

#include "utils_mini2.h"

list_t *new_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->length = 0;
    list->start = NULL;
    list->end = NULL;
    return (list);
}