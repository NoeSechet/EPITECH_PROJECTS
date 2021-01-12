/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include "utils.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}

int show_num(char const *str, int nb, int i)
{
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb);
}

void num_neg(int n, int *nb)
{
    if (n % 2 == 1)
        *nb = -*nb;
}

int my_getnbr(array_t *arr, char const *str)
{
    int i = 0;
    int nb = 0;
    int n = 0;

    if (str[i] == '\0')
        return (0);
    if (!(str[i] >= '0' && str[i] <= '9') &&
    (str[i] != '-' && str[i] != '+' )) {
        arr->false_nbr = 1;
            return (0);
    }
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
                n++;
        i++;
    }
    nb = show_num(str, nb, i);
    num_neg(n, &nb);
    return (nb);
}