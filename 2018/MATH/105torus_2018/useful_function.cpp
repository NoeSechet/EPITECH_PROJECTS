/*
** EPITECH PROJECT, 2018
** useful function
** File description:
** useful_function
*/

#include "torus.hpp"

int str_cmp(char const *s1, char const *s2)
{
    return (std::string(s1).compare(s2) == 0);
}

int help(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]).compare("-h") == 0) {
        std::cout << "USAGE\n    ./105torus opt a0 a1 a2 a3 a4 n\n\n"
        << "DESCRIPTION\n    opt       method option:\n"
        << "\t\t    1 for the bisection method\n\t\t    "
        << "2 for Newton's method\n\t\t    3 for the secant method\n"
        << "    a[0-4]    coefficients of the equation\n    n         "
        << "precision (the application of the polynomial to"
        << "the solution shold\n\t      be smaller than 10^-n)"
        << std::endl;
    }
    return (84);
}

int is_number(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
            return (1);
        i++;
    }
    return (0);
}

int check_arg(char **argv)
{
    int i = 1;

    while (argv[i])
    {
        if (is_number(argv[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}