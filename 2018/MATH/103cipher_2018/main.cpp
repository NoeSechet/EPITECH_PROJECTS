/*
** EPITECH PROJECT, 2018
** main
** File description:
** main.c
*/

#include "cipher.hpp"

void encrypt(char **argv)
{
    int key_line = ceil(sqrt(strlen(argv[2])));
    double **key = fill_matrix_key(argv[2], key_line);
    double **cipher = fill_matrix_cipher(argv[1], key_line);

    print_key(key, key_line);
    multiply_matrix(key, cipher, argv, key_line);
}

void decrypt(char **av)
{
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (help(argc, argv));
    if (str_cmp(argv[3], "0") == 1)
        encrypt(argv);
    else if (str_cmp(argv[3], "1") == 1)
        decrypt(argv);
    else
        return (84);
}