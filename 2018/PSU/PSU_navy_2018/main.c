/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "utils.h"

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (84);

    if (is_description(av[1]) == 1)
        return (0);

    if (ac == 2)
        return (program_1(av[1]));
    else
        return (program_2(my_getnbr(av[1]), av[2]));
    return (0);
}