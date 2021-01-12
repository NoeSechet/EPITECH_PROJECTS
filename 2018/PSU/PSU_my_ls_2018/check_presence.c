/*
** EPITECH PROJECT, 2019
** check_flag_presence.c
** File description:
** check_flag_presence.c
*/

#include "utils.h"

int check_flag_presence(int ac, char **av)
{
    for (int i = 0; i < ac; i += 1) {
        if (av[i][0] == '-')
            return (1);
    }
    return (0);
}

int check_file_presence(int ac, char **av)
{
    for (int i = 0; i < ac; i += 1) {
        if (av[i][0] != '-')
            return (1);
    }
    return (0);
}