/*
** EPITECH PROJECT, 2018
** rotate_right.c
** File description:
** rotate_right
*/

#include "utils.h"

void rotate_right(int *array, int size)
{
    int temp = array[size - 1];
    int parser = size - 1;

    while (parser > 0) {
        array[parser] = array[parser - 1];
        parser -= 1;
    }
    array[0] = temp;
}