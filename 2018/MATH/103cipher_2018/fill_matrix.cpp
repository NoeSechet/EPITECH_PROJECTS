/*
** EPITECH PROJECT, 2018
** fill_matrix.cpp
** File description:
** fill_matrix
*/

#include "cipher.hpp"

double **fill_matrix_key(char *str, int key_line)
{
    int i = 0;
    int j;
    int k = 0;
    double **key = new double*[key_line];

    for(int m = 0; m <= key_line; m++)
        key[m] = new double[key_line];
    while (k <= key_line) {
        j = 0;
        while (j < key_line && str[i]) {
            key[k][j] = str[i];
            j++;
            i++;
        }
        k++;
    }
    return (key);
}

double **fill_matrix_cipher(char *str, int key_line)
{
    int nbr_line = ceil(strlen(str) / key_line);
    int i = 0;
    int j;
    int k = 0;
    double **cipher = new double*[nbr_line];

    for(int m = 0; m <= nbr_line; m++)
        cipher[m] = new double[key_line];
    while (k <= nbr_line) {
        j = 0;
        while (j < key_line && str[i]) {
            cipher[k][j] = str[i];
            j++;
            i++;
        }
        k++;
    }
    return (cipher);
}

void print_key(double **key, int key_line)
{
    int j = 0;

    std::cout << "Key matrix:" << std::endl;
    for(int i = 0; i < key_line; i += 1) {
        j = 0;
        for (; j < key_line - 1; j += 1)
            printf("%.0f\t", key[i][j]);
        printf("%.0f\n", key[i][j]);
    }
    std::cout << "\nEncrypted message:" << std::endl;
}