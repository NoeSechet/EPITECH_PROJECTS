/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** minishell1
*/

#include "include_linked_list/linked_list.h"
#include "mysh.h"

void pop_elem_haroun(list_t *list, elem_t *elem)
{
    if (elem == list->end) {
        pop_back_haroun(list);
        return;
    } else if (elem == list->start) {
        pop_front_haroun(list);
        return;
    }
    if (list && elem) {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        list->size--;
    }
}

void pop_back_haroun(list_t *list)
{
    if (list->end != NULL) {
        list->end = list->end->prev;
        list->end->next = NULL;
        list->size--;
    }
    if (list->end != NULL && list->size == 1)
        init_list_haroun(list);
}

void pop_front_haroun(list_t *list)
{
    if (list->start != NULL) {
        list->start = list->start->next;
        list->start->prev = NULL;
        list->size--;
    }
    if (list->size == 1)
        init_list_haroun(list);
}

void init_list_haroun(list_t *list)
{
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
}

elem_t *create_new_elem_haroun(char *data)
{
    elem_t *elem = malloc(sizeof(elem_t));

    if (data == NULL)
        return (NULL);
    if (elem != NULL) {
        elem->data = my_strdup(data);
        elem->prev = NULL;
        elem->next = NULL;
    }
    return (elem);
}
