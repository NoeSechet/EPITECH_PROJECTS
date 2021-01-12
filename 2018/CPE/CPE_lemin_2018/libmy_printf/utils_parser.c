/*
** EPITECH PROJECT, 2018
** utils_parser.c
** File description:
** utils_parser
*/

#include "utils_printf.h"

int convert_nbr(char const *str, int *index)
{
    int nbr = 0;

    while (str[*index] >= '0' && str[*index] <= '9') {
        nbr = nbr * 10 + (str[*index] - '0');
        *index += 1;
    }
    return (nbr);
}

int my_strncmp(char const *s1, char const *s2, int n, int *index)
{
    int compare = 1;
    int i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0') && i < n) {
        if (s1[i] != s2[i]) {
            *index -= i;
            return (-1);
        }
        *index += 1;
        i += 1;
    }
    return (compare);
}