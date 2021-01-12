/*
** EPITECH PROJECT, 2018
** initiate_array_struct.c
** File description:
** initiate_array_struct
*/

#include "utils.h"

int fill_array_struct(array_t *arr, char **av)
{
    for (int i = 0; i < arr->size; i++) {
        arr->list[i] = my_getnbr(arr, av[i + 1]);
        if (arr->false_nbr == 1)
            return (0);
        if (i == 0)
            arr->min_value = arr->list[0];
        if (arr->min_value > arr->list[i])
            arr->min_value = arr->list[i];
    }
    return (0);
}

array_t *inititate_array_struct(int ac)
{
    array_t *arr = malloc(sizeof(array_t));

    arr->size = ac - 1;
    arr->min_value = 0;
    arr->false_nbr = 0;
    arr->list = malloc(sizeof(int) * arr->size);
    return (arr);
}