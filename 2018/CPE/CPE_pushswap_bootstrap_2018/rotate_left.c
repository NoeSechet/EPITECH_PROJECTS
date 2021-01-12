/*
** EPITECH PROJECT, 2018
** rotate_left.c
** File description:
** rotate_left
*/

#include "utils.h"

void rotate_left(int *array, int size)
{
    int temp = array[0];
    int parser = 0;

    while (parser < size - 1) {
        array[parser] = array[parser + 1];
        parser += 1;
    }
    array[size - 1] = temp;
}