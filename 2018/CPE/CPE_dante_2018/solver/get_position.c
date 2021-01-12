/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "utils_dante.h"

int current_column(int current_pos, int width)
{
    return ((current_pos) % width + 1);
}

int current_line(int current_pos, int width)
{
    return ((current_pos) / width + 1);
}