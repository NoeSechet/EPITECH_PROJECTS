/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#include "array_struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr (array_t *arr, char const *str);
void swap_element(array_t *arr);
void rotate_left(array_t *arr);
array_t *inititate_array_struct(int ac);
int fill_array_struct(array_t *arr, char **av);
int transform(array_t *arr);
int check_order(array_t *arr);

#endif