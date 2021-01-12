/*
** EPITECH PROJECT, 2018
** multiply_matrix.cpp
** File description:
** multiply_matrix
*/

#include "cipher.hpp"

int mult(double **cipher, double **key, int tab[4], int result)
{
    if (result != 0)
        printf(" ");
    result = 0;
    for (int l = 0; l < tab[1]; l += 1)
        result = result + (cipher[tab[0]][l] * key[l][tab[3]]);
    return (result);
}

void multiply_matrix(double **key, double **cipher, char **av, int key_line)
{
    int len = strlen(av[1]);
    int result = 0;
    int l = 0;
    int tab[5] = {1, 2, 3, 4, 0};
    len = (key_line == 1 ? len - 1 : len);

    for (int i = 0; i <= (len / key_line); i += 1)
        for (int width = 0; width < key_line; width += 1) {
            tab[0] = i;
            tab[1] = key_line;
            tab[2] = len;
            tab[3] = width;
            result = mult(cipher, key, tab, result);
            printf("%d", result);
        }
    printf("\n");
}