/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** errors.c
*/

#include "include/utils.h"

int check_line_errors(int chosen_line, int nb_line)
{
    if (chosen_line == 0 || chosen_line > nb_line) {
        write(1, "Error: this line is out of range\n", 33);
        return (1);
    }
    if (chosen_line == -2 || chosen_line == -1) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    return (0);
}

int check_remov_errors(int chosen_remov, int nb_sticks, int max_remov)
{
    if (chosen_remov == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (1);
    } else if (chosen_remov > max_remov) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(max_remov);
        write(1, " matches per turn\n", 18);
        return (1);
    } else if (chosen_remov > nb_sticks) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    } else if (chosen_remov == -2 || chosen_remov == -1) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    return (0);
}