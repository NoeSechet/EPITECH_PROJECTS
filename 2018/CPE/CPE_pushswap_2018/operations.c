/*
** EPITECH PROJECT, 2018
** operations.c
** File description:
** operations
*/

#include "utils.h"

void rotate_left(array_t *arr)
{
    int temp = arr->list[0];
    int counter = 0;

    while (counter < arr->size - 1) {
        arr->list[counter] = arr->list[counter + 1];
        counter++;
    }
    arr->list[arr->size - 1] = temp;
    my_putstr("ra");
}

void swap_element(array_t *arr)
{
    int save = 0;

    save = arr->list[0];
    arr->list[0] = arr->list[1];
    arr->list[1] = save;
    my_putstr("sa");
}