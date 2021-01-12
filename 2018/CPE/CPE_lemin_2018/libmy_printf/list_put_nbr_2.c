/*
** EPITECH PROJECT, 2018
** list_put_nbr_2.c
** File description:
** list_put_nbr_2
*/

#include "utils_printf.h"

void my_put_nbr_base_u_long(unsigned long nb, char *base)
{
    uint a = 0;

    while (base[a] != '\0')
        a += 1;
    if (nb >= a) {
        my_put_nbr_base_u_long(nb / a, base);
        my_put_nbr_base_u_long(nb % a, base);
    } else {
        my_putchar(base[nb]);
    }
}

void my_put_nbr_base_u_long_long(unsigned long long nb, char *base)
{
    uint a = 0;

    while (base[a] != '\0')
        a += 1;
    if (nb >= a) {
        my_put_nbr_base_u_long_long(nb / a, base);
        my_put_nbr_base_u_long_long(nb % a, base);
    } else {
        my_putchar(base[nb]);
    }
}