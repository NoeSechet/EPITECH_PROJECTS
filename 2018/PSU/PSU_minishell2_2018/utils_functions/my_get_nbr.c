/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** my_get_nbr.c
*/

#include "utils_mini2.h"

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

int my_get_nbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int n = 0;

    if (str == NULL)
        return (0);
    if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '-' && str[i] != '+' ))
        return (0);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            n++;
        i++;
    }
    nb = show_num(str, nb, i);
    num_neg(n, &nb);
    return (nb);
}