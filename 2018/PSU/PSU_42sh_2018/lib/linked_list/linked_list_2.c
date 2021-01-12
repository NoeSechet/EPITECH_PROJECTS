/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "include_linked_list/linked_list.h"

void norme_function(list_t *list, elem_t *new_elem, int pos)
{
    int i = 0;

    for (elem_t *elem = list->start; elem != NULL
        && i < pos; elem = elem->next, i++) {
        new_elem->next = elem->next;
        new_elem->prev = elem;
        elem->next = new_elem;
        new_elem->next->prev = new_elem;
        list->size++;
    }
}

bool push_elem_haroun(list_t *list, char *data, int pos)
{
    elem_t *new_elem = create_new_elem_haroun(data);

    if (list->end == NULL && new_elem != NULL)
        push_back_haroun(list, data);
    else if (list->start == NULL && new_elem != NULL)
        push_front_haroun(list, data);
    else
        norme_function(list, new_elem, pos);
    return (true);
}

bool push_back_haroun(list_t *list, char *data)
{
    elem_t *elem = create_new_elem_haroun(data);

    if (elem == NULL)
        return (false);
    if (list->end == NULL) {
        list->end = elem;
        list->start = elem;
        list->size++;
    } else {
        list->end->next = elem;
        elem->prev = list->end;
        list->end = elem;
        list->size++;
    }
    return (true);
}

bool push_front_haroun(list_t *list, char *data)
{
    elem_t *elem = create_new_elem_haroun(data);

    if (elem == NULL)
        return (false);
    if (list->start == NULL) {
        list->end = elem;
        list->start = elem;
        list->size++;
    } else {
        list->start->prev = elem;
        elem->next = list->start;
        list->start = elem;
        list->size++;
    }
    return (true);
}
