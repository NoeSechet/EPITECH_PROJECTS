/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** insert_move.c
*/

#include "utils_dante.h"

move_t *init_new_move(int new_pos)
{
    move_t *new_move = malloc(sizeof(move_t));

    new_move->pos = new_pos;
    new_move->next = NULL;
    new_move->previous = NULL;

    return (new_move);
}

void insert_move(stack_list_t *stack_list, int new_pos)
{
    move_t *new_move = init_new_move(new_pos);

    if (stack_list->size == 0) {
        stack_list->start = new_move;
        stack_list->end = new_move;
    } else {
        stack_list->end->next = new_move;
        new_move->previous = stack_list->end;
        stack_list->end = new_move;
    }
    stack_list->size += 1;
}