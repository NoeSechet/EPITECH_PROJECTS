/*
** EPITECH PROJECT, 2019
** convert_binary_code.c
** File description:
** convert_binary_code.c
*/

#include "include/utils.h"

char *deci_into_bin(int decimal_nbr)
{
    char *binary_nbr = malloc(sizeof(char) * (8 + 1));
    char temp;
    int i = 0;

    for (; decimal_nbr != 0; i += 1, decimal_nbr /= 2)
        if (decimal_nbr % 2 != 0)
            binary_nbr[i] = '1';
        else
            binary_nbr[i] = '0';

    for (; i < 8; i += 1)
        binary_nbr[i] = '0';
    binary_nbr[8] = '\0';
    for (int i = 0, j = my_strlen(binary_nbr) - 1;
            i < my_strlen(binary_nbr) / 2; i += 1, j -= 1) {
        temp = binary_nbr[i];
        binary_nbr[i] = binary_nbr[j];
        binary_nbr[j] = temp;
    }
    return (binary_nbr);
}

int bin_into_deci(char *binary_nbr)
{
    (void)binary_nbr;
    char decimal_nbr = 0;

    if (my_strlen(binary_nbr) != 8)
        return (-1);

    for (int i = 0, powers = 128; i != 8; i += 1, powers /= 2)
        if (binary_nbr[i] == '1')
            decimal_nbr += powers;

    return (decimal_nbr);
}