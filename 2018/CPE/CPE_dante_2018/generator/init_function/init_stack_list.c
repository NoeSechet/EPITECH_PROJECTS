/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** init_stack_list.c
*/

#include "utils_dante.h"

stack_list_t *init_stack_list(void)
{
    stack_list_t *stack_list = malloc(sizeof(stack_list_t));

    stack_list->start = NULL;
    stack_list->end = NULL;
    stack_list->size = 0;

    insert_move(stack_list, 0);

    return (stack_list);
}