/*
** EPITECH PROJECT, 2018
** final_square.c
** File description:
** final_square
*/

#include "utils.h"

int single_point_square(char *buf)
{
    int i = 0;
    int c = 0;

    while (buf[i] != '\0') {
        if (buf[i] == '.' && c == 0) {
            buf[i] = 'x';
            c += 1;
        }
        i += 1;
    }
    my_putstr(buf);
    exit (0);
}

void final_square(char *buf, coord_t *Sq_coords, int lineLength)
{
    int line = Sq_coords->nx - (Sq_coords->maxSize - 1);
    int column = Sq_coords->ny - (Sq_coords->maxSize - 1);

    while (column <= Sq_coords->ny) {
        while (line <= Sq_coords->nx) {
            buf[line + (lineLength + 1) * column] = 'x';
            line += 1;
        }
        line = Sq_coords->nx - (Sq_coords->maxSize - 1);
        column += 1;
    }
    write(1, buf, Sq_coords->size);
}