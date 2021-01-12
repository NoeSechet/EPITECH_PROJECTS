/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** main.c
*/

#include "./include_vector/vector.h"

arraylist_t *create_list(int size)
{
    arraylist_t *list = malloc(sizeof(arraylist_t));

    list->size_alloc = size;
    list->nb_elem = 0;
    list->array = malloc(sizeof(void *) * size);
    list->max_width = 0;
    list->max_height = 0;

    return (list);
}

void delete_list(arraylist_t *list)
{
    free(list->array);
    list->array = NULL;
    free(list);
}