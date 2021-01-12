/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** move_elem.c
*/

#include "./include_vector/vector.h"

void resize_list_size(arraylist_t *list)
{
    void **new_list = 0;

    new_list = malloc(sizeof(void *) * (list->size_alloc * 2));
    for (int i = 0; i < list->nb_elem; i += 1) {
        new_list[i] = list->array[i];
    }
    free(list->array);
    list->array = new_list;
    list->size_alloc *= 2;
}

void add_elem(arraylist_t *list, void *elem)
{
    if (list->size_alloc < list->nb_elem + 1) {
        resize_list_size(list);
    }
    list->array[list->nb_elem] = elem;
    list->nb_elem += 1;
}

void remove_elem_at(arraylist_t *list, int pos)
{
    if (pos > list->nb_elem || pos < 0)
        return;
    for (int i = pos; i < list->nb_elem - 1; i += 1) {
        list->array[i] =
        list->array[i + 1];
    }
    list->nb_elem -= 1;
}

void *get_elem_at(arraylist_t *list, int pos)
{
    if (pos > list->nb_elem || pos < 0)
        return (NULL);
    return (list->array[pos]);
}