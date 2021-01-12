/*
** EPITECH PROJECT, 2019
** ls_utils.c
** File description:
** ls_utils.c
*/

#include "utils.h"

int calc_nb_space(int size)
{
    int len_size = 0;

    while (size != 0) {
        size /= 10;
        len_size += 1;
    }
    return (len_size);
}