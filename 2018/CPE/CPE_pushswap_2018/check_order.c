/*
** EPITECH PROJECT, 2018
** check_order.c
** File description:
** check_order
*/

#include "utils.h"

int check_order(array_t *arr)
{
    for (int i = 0; i < arr->size - 1; i++) {
        if (arr->list[i] > arr->list[i + 1])
            return (0);
    }
    return (1);
}