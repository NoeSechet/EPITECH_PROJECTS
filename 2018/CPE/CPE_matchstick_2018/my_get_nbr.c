/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** my_get_nbr.c
*/

#include "include/utils.h"

int my_get_nbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int n = 0;

    if (str[i] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i += 1)
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\n'))
            return (-2);
    while (str[i] == '-' || str[i] == '+') {
        (str[i] == '-') ? n += 1 : 0;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    if (n % 2 == 1)
        return (-1);
    return (nb);
}