/*
** EPITECH PROJECT, 2018
** padder_functions.c
** File description:
** padder_functions
*/

#include "utils.h"

void spaces_padder_int(int nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar(' ');
        padding -= 1;
    }
}

void spaces_padder_int_long(long int nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar(' ');
        padding -= 1;
    }
}

void spaces_padder_int_long_long(long long int nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar(' ');
        padding -= 1;
    }
}

void spaces_padder_int_u(uint nbr, int padder)
{
    int count = 0;
    int padding = 0;

    while (nbr > 0) {
        nbr /= 10;
        count += 1;
    }
    padding = padder - count;
    while (padding > 0) {
        my_putchar(' ');
        padding -= 1;
    }
}

void spaces_padder_string(char *str, int padder)
{
    int len = padder - my_strlen(str);

    while (len > 0) {
        my_putchar(' ');
        len -= 1;
    }
}