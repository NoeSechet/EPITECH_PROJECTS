/*
** EPITECH PROJECT, 2018
** arraylist
** File description:
** arraylist
*/

#include <stdlib.h>
#include "arraylist.h"

arraylist_t *new_arraylist(void)
{
    arraylist_t *list = malloc(sizeof(arraylist_t));
    list->size = 0;
    list->list = NULL;
    return (list);
}

void resize_list(arraylist_t *list, int size)
{
    void **newlist = 0;
    int j = 0;

    if (size > 0)
        newlist = malloc(sizeof(void *) * (size));
    for (int i = 0; j < size && i < list->size; i++)
        if (list->list[i] != NULL) {
            newlist[j] = list->list[i];
            j++;
        }
    if (list->list != 0)
        free(list->list);
    list->list = newlist;
    list->size = size > 0 ? size : 0;
}

void arraylist_add(arraylist_t *list, void *obj)
{
    if (list != NULL) {
        resize_list(list, list->size + 1);
        list->list[list->size - 1] = obj;
    }
}

void *arraylist_remove(arraylist_t *list, int index)
{
    void *obj = 0;

    if (list != NULL) {
        obj = list->list[index];
        if (index > -1 && index < list->size) {
            list->list[index] = NULL;
            resize_list(list, list->size - 1);
            return (obj);
        }
    }
    return (NULL);
}

void *arraylist_get(arraylist_t *list, int index)
{
    if (index > -1 && index < list->size)
        return (list->list[index]);
    return (NULL);
}