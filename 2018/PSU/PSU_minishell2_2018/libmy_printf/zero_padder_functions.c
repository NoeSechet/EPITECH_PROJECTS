/*
** EPITECH PROJECT, 2018
** zero_padder_functions.c
** File description:
** zero_padder_functions
*/

#include "utils_printf.h"

void zero_padder_int(int nbr, int padder)
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

void zero_padder_int_long(long int nbr, int padder)
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

void zero_padder_int_long_long(long long int nbr, int padder)
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

void zero_padder_int_u(uint nbr, int padder)
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

void zero_padder_string(char *str, int padder)
{
    int len = padder - my_strlen(str);

    while (len > 0) {
        my_putchar('0');
        len -= 1;
    }
}