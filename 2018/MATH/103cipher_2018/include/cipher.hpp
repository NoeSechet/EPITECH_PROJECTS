/*
** EPITECH PROJECT, 2018
** cipher.h
** File description:
** cipher.h
*/

#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

int help(int argc, char **argv);
int str_cmp(char const *s1, char const *s2);
double **fill_matrix_key(char *str, int key_line);
double **fill_matrix_cipher(char *str, int key_line);
void print_key(double **key, int line);
void multiply_matrix(double **key, double **cipher, char **av, int key_line);

#endif
