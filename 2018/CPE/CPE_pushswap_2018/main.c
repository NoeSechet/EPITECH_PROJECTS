/*
** EPITECH PROJECT, 2018
** push_swap.c
** File description:
** push_swap
*/

#include "utils.h"

int sort_function(array_t *arr)
{
    if (check_order(arr))
        return (1);
    while (1) {
        transform(arr);
        if (check_order(arr))
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    array_t *arr = inititate_array_struct(ac);

    if (ac < 2)
        return (84);
    fill_array_struct(arr, av);
    if (arr->false_nbr == 1)
        return (84);
    sort_function(arr);
    my_putchar('\n');
    return (0);
}