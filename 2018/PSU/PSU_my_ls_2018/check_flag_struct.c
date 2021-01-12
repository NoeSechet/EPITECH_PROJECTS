/*
** EPITECH PROJECT, 2019
** check_file.c
** File description:
** check_file.c
*/

#include "utils.h"

void check_flag_struct(char **av, flag_t *flag, int i)
{
    if (flag->l == 1 && flag->d == 0 && flag->t == 0 && flag->R == 0
    && flag->r == 0)
        l_flag(av[i]);
    if (flag->d == 1 && flag->l == 0 && flag->t == 0 && flag->R == 0
    && flag->r == 0)
        d_flag(av[i]);
    if (flag->t == 1 && flag->l == 0 && flag->d == 0 && flag->R == 0
    && flag->r == 0)
        t_flag(av[i]);
}