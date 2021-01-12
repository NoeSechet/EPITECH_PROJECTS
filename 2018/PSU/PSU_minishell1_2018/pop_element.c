/*
** EPITECH PROJECT, 2019
** pop_element.c
** File description:
** pop_element.c
*/

#include "include/utils.h"

void pop_front(list_t *list)
{
    elem_t *temp = list->start;

    list->start = list->start->next;
    list->start->previous = NULL;
    temp->next = NULL;
    temp->previous = NULL;

    free(temp);
    temp = NULL;
}

void pop_back(list_t *list)
{
    elem_t *temp = list->end;

    list->end = list->end->previous;
    list->end->next = NULL;
    temp->next = NULL;
    temp->previous = NULL;

    free(temp);
    temp = NULL;
}

void pop_temp(elem_t *temp)
{
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    temp->next = NULL;
    temp->previous = NULL;

    free(temp);
    temp = NULL;
}

void detect_pop_position(list_t *list, int index)
{
    int i = 1;
    int j = list->length - 1;

    for (elem_t *temp1 = list->start, *temp2 = list->end; temp1 != NULL ||
    temp2 != NULL; i += 1, j -= 1) {
        temp1 = temp1->next;
        temp2 = temp2->previous;
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
    if (list->length == 0 || index < 1 || index > list->length)
        return (list);
    if (list->length == 1) {
        free(list->start);
        list->start = NULL;
        list->end = NULL;
    } else if (index == 1) {
        pop_front(list);
        list->length -= 1;
        return (list);
    }
    if (index == list->length)
        pop_back(list);
    else if (index > 1 && index < list->length)
        detect_pop_position(list, index);
    list->length -= 1;
    return (list);
}