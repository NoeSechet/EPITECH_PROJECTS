/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils.c
*/

#include "include/utils.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

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