/*
** EPITECH PROJECT, 2018
** h_instructions.c
** File description:
** h_instructions
*/

#include "utils.h"

void h_instructions(void)
{
    write(0, "USAGE\n    ./my_sokoban map\nDESCRIPTION\n    map file ", 52);
    write(0, "representing the warehouse map, contaning '#' for walls", 55);
    write(0, "\n        'P' for the player, 'X' for the boxes and 'O' ", 55);
    write(0, "for storage locations.\n", 23);
}

void instructions(char **av)
{
    if (my_strncmp(av[1], "-h", 2) == 1) {
        h_instructions();
        exit (84);
    }
}