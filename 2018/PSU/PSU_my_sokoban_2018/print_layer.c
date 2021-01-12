/*
** EPITECH PROJECT, 2018
** print_layer.c
** File description:
** print_layer
*/

#include "utils.h"

void check_print_sky(char **sky, int y)
{
    for (int x = 0; sky[y][x] != '\0'; x += 1)
        if (sky[y][x] == 'P' || sky[y][x] == 'X')
            mvprintw(y, x, "%c", sky[y][x]);
}

void print_sky(char **sky)
{
    for (int y = 0; sky[y] != NULL; y += 1) {
        check_print_sky(sky, y);
    }
}

void print_map(char **map)
{
    for (int y = 0; map[y] != NULL; y += 1) {
        printw("%s", map[y]);
    }
}