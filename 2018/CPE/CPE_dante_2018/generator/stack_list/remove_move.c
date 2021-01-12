/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** remove_move.c
*/

#include "utils_dante.h"

void remove_move(stack_list_t *stack_list)
{
    if (stack_list->size == 0)
        return;
    if (stack_list->size == 1) {
        free(stack_list->start);
        stack_list->start = NULL;
        stack_list->end = NULL;
    } else {
        stack_list->end = stack_list->end->previous;
        stack_list->end->next->previous = NULL;
        free(stack_list->end->next);
        stack_list->end->next = NULL;
    }
    stack_list->size -= 1;
}