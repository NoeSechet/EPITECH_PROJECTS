/*
** EPITECH PROJECT, 2018
** zero_padder_functions_2.c
** File description:
** zero_padder_functions_2
*/

#include "utils.h"

void zero_padder_int_u_long(long unsigned nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar('0');
        padding -= 1;
    }
}

void zero_padder_int_u_long_long(long long unsigned int nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar('0');
        padding -= 1;
    }
}