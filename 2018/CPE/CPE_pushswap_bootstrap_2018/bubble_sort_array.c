/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <stdio.h>
#include "utils.h"

void swap_elem(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void bubble_sort_array(int *array, int size)
{
    int index1 = 0;
    int index2 = 0;
    int parser = 0;

    while (parser < size - 1) {
        if (array[parser] > array[parser + 1]) {
            index1 = parser;
            index2 = parser + 1;
            swap_elem(array, index1, index2);
            parser = 0;
        } else {
            parser += 1;
        }
    }
}

int main(void)
{
    int array[6] = {2, 3, 6, 1, 5, 4};
    int size = 6;

    bubble_sort_array(array, size);
    rotate_left(array, size);
    for (int i = 0; i < size; i += 1) {
        printf("%d", array[i]);
    }
    printf("\n");
    rotate_right(array, size);
    for (int i = 0; i < size; i += 1) {
        printf("%d", array[i]);
    }
    return (0);
}