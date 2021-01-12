/*
** EPITECH PROJECT, 2019
** int_to_char
** File description:
** int_to_char
*/

#include "utils_lem_in.h"

char *int_to_char(int nbr)
{
    char *str = NULL;
    int temp = nbr;
    int i = 0;
    int j = 0;

    nbr <= 0 ? i += 1, nbr *= -1 : 0;
    for (int temp = nbr; temp != 0; temp /= 10, i += 1);
    str = malloc(sizeof(char) * (i + 1));
    nbr < 0 ? str[0] = '-', j += 1 : 0;
    for (int k = i - 1; j < i; j += 1, nbr /= 10, k -= 1)
        str[k] = (nbr % 10) + 48;
    temp < 0 ? str[0] = '-', j += 1 : 0;
    str[i] = '\0';
    return (str);
}