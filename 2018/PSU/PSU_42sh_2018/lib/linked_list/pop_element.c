/*
** EPITECH PROJECT, 2019
** pop_element.c
** File description:
** pop_element.c
*/

#include "include_linked_list/linked_list.h"

void pop_start(list_t *list)
{
    if (list->start == NULL)
        return;
    if (list->size > 1) {
        list->start = list->start->next;
        free(list->start->prev);
        list->start->prev = NULL;
    } else if (list->size == 1) {
        free(list->start);
        list->start = NULL;
        list->end = NULL;
    }
    list->size--;
}

void pop_end(list_t *list)
{
    if (list->end == NULL)
        return;
    if (list->size > 1) {
        list->end = list->end->prev;
        free(list->end->next);
        list->end->next = NULL;
    } else if (list->size == 1) {
        free(list->end);
        list->start = NULL;
        list->end = NULL;
    }
    list->size--;
}

void pop_temp(elem_t *temp)
{
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    temp = NULL;
}

void detect_pop_position(list_t *list, int index)
{
    int i = 1;
    int j = list->size - 1;

    for (elem_t *temp1 = list->start, *temp2 = list->end; temp1 != NULL ||
    temp2 != NULL; i += 1, j -= 1) {
        temp1 = temp1->next;
        temp2 = temp2->prev;
        if (i == index) {
            pop_temp(temp1);
            break;
        } else if (j == index) {
            pop_temp(temp2);
            break;
        }
    }
}

list_t *pop_element_at(list_t *list, int index)
{
    if (list->size == 0 || index < 1 || index > list->size)
        return (list);
    if (list->size == 1) {
        free(list->start);
        list->start = NULL;
        list->end = NULL;
    } else if (index == 1) {
        pop_start(list);
        list->size -= 1;
        return (list);
    }
    if (index == list->size)
        pop_end(list);
    else if (index > 1 && index < list->size)
        detect_pop_position(list, index);
    list->size -= 1;
    return (list);
}