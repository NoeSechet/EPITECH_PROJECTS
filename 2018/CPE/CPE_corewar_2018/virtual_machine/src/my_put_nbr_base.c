/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** my_put_nbr_base.c
*/

#include "lib.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_strlen(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len += 1);
    return (len);
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