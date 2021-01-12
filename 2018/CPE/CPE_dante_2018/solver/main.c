/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** main.c
*/

#include "utils_dante.h"

// erreur
// 3 par 3 minim
// pas carré, rectangulaire

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    get_maze(av[1]);
    return (0);
}
