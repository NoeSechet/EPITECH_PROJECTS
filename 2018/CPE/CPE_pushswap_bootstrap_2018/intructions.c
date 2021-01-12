/*
** EPITECH PROJECT, 2018
** instructions.c
** File description:
** instructions
*/

#include "utils.h"

void swap_elem(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}
void rotate(int parser)
{
    while (parser > 0) {
        parser -= 1;
        printf("rotate_right\n");
    }
}

void my_amazing_sorter(int *array, int size)
{
    int index1 = 0;
    int index2 = 0;
    int parser = 0;

    while (parser < size - 1) {
        if (array[parser] > array[parser + 1]) {
            index1 = parser;
            index2 = parser + 1;
            swap_elem(array, index1, index2);
            printf("swap\n");
            rotate(parser);
            parser = 0;
        } else {
            parser += 1;
            printf("rotate_left\n");
        }
    }
    printf("rotate_left\n");
}

int main(void)
{
    int array[6] = {15, 8, 42, 4, 16, 23};
    int size = 6;

    my_amazing_sorter(array, size);
    return (0);
}

// 3 4 1 2 left
// 4 1 2 3 swap
// 1 4 2 3 right
// 3 1 4 2 