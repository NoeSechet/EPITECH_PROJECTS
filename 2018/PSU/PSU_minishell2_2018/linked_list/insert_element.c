/*
** EPITECH PROJECT, 2019
** push_elem.c
** File description:
** push_elem.c
*/

#include "utils_mini2.h"

void push_front(list_t *list, elem_t *elem)
{
    list->start->previous = elem;
    elem->next = list->start;
    list->start = elem;
}

void push_back(list_t *list, elem_t *elem)
{
    list->end->next = elem;
    elem->previous = list->end;
    list->end = elem;
}

void move_temp(elem_t *temp, elem_t *elem)
{
    temp->previous->next = elem;
    temp->previous = elem;
    elem->previous = temp->previous;
    elem->next = temp;
}

void detect_position(list_t *list, elem_t *elem, int index)
{
    int i = 1;
    int j = list->length;

    for (elem_t *temp1 = list->start, *temp2 = list->end; temp1 != NULL ||
    temp2 != NULL; i += 1, j -= 1) {
        temp1 = temp1->next;
        temp2 = temp2->previous;
        if (i == index) {
            move_temp(temp1, elem);
            break;
        } else if (j == index) {
            move_temp(temp2, elem);
            break;
        }
    }
}

void insert_element_at(list_t *list, char *str, int index)
{
    elem_t *elem = malloc(sizeof(elem_t));

    if (elem == NULL)
        return;
    elem->str = str;
    elem->previous = NULL;
    elem->next = NULL;
    if (list->length == 0) {
        list->start = elem;
        list->end = elem;
    } else if (index == 1) {
        push_front(list, elem);
        list->length += 1;
        return;
    }
    if (index == list->length)
        push_back(list, elem);
    else if (index > 1 && index < list->length)
        detect_position(list, elem, index);
    list->length += 1;
}