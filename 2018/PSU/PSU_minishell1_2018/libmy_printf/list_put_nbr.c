/*
** EPITECH PROJECT, 2018
** list_put_nbr.c
** File description:
** list_put_nbr
*/

#include "utils.h"

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}

void my_put_nbr_base(int nb, char *base)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    if (nb >= my_strlen(base)) {
        my_put_nbr_base(nb / my_strlen(base), base);
        my_put_nbr_base(nb % my_strlen(base), base);
    } else {
        my_putchar(base[nb]);
    }
}

void my_put_nbr_base_u(uint nb, char *base)
{
    uint a = 0;

    while (base[a] != '\0')
        a += 1;
    if (nb >= a) {
        my_put_nbr_base_u(nb / a, base);
        my_put_nbr_base_u(nb % a, base);
    } else {
        my_putchar(base[nb]);
    }
}

void my_put_nbr_base_long(long nb, char *base)
{
    uint a = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    while (base[a] != '\0')
        a += 1;
    if (nb >= a) {
        my_put_nbr_base_long(nb / a, base);
        my_put_nbr_base_long(nb % a, base);
    } else {
        my_putchar(base[nb]);
    }
}

void my_put_nbr_base_long_long(long long nb, char *base)
{
    uint a = 0;

    if (nb < 0) {
        nb = -nb;
        my_putchar ('-');
    }
    while (base[a] != '\0')
        a += 1;
    if (nb >= a) {
        my_put_nbr_base_long_long(nb / a, base);
        my_put_nbr_base_long_long(nb % a, base);
    } else {
        my_putchar(base[nb]);
    }
}