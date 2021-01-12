/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** check_column_line.c
*/

#include "utils_dante.h"

int current_column(int current_pos, int x)
{
    return ((current_pos) % x + 1);
}

int current_line(int current_pos, int x)
{
    return (current_pos / x + 1);
}