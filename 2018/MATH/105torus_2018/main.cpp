/*
** EPITECH PROJECT, 2019
** torus
** File description:
** torus
*/

#include "torus.hpp"

int main(int argc, char **argv)
{
    if (argc != 8)
        return (help(argc, argv));
    if (check_arg(argv) == 1)
        return (84);
    torus torus(argv);
    return (torus.solver());
}