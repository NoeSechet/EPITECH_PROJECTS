/*
** EPITECH PROJECT, 2018
** sort_function.c
** File description:
** sort_function
*/

#include "utils.h"

int min_value_sec_pos(array_t *arr)
{
    if (arr->list[1] == arr->min_value) {
        rotate_left(arr);
        if (check_order(arr) == 1)
            return (0);
        else {
            my_putchar(' ');
            rotate_left(arr);
            my_putchar(' ');
        }
    } else {
        swap_element(arr);
        my_putchar(' ');
    }
    return (0);
}

int transform(array_t *arr)
{
    if (arr->list[0] > arr->list[1]) {
        min_value_sec_pos(arr);
        if (check_order(arr) == 1)
            return (0);
    } else {
        rotate_left(arr);
        my_putchar(' ');
    }
    return (0);
}