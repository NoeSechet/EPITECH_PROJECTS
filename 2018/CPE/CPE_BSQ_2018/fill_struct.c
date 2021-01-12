/*
** EPITECH PROJECT, 2018
** fill_struct.c
** File description:
** fill_struct
*/

#include "utils.h"

void fill_struct(coord_t *Sq_coords, int *clone)
{
    Sq_coords->nx = 0;
    Sq_coords->ny = 0;
    Sq_coords->maxSize = 0;
    Sq_coords->clone = clone;
}

int square_coords(coord_t *Sq_coords, int x, int y, int *lineLength)
{
    int actual_coords = check_coords(x, y, lineLength);
    int top_left_coords = check_coords(x - 1, y - 1, lineLength);
    int top_coords = check_coords(x, y - 1, lineLength);
    int left_coords = check_coords(x - 1, y, lineLength);

    if (Sq_coords->clone[actual_coords] == 1)
        Sq_coords->clone[actual_coords] =
        (min(min(Sq_coords->clone[top_left_coords],
        Sq_coords->clone[top_coords]), Sq_coords->clone[left_coords])) + 1;
    return (Sq_coords->clone[actual_coords]);
}

void set_coord(int *lineLength, int *line_nbr, coord_t *Sq_coords)
{
    int x = 1;
    int y = 1;
    int value = 0;

    while (y < *line_nbr) {
        value = square_coords(Sq_coords, x, y, lineLength);
        if (value > Sq_coords->maxSize) {
            Sq_coords->nx = x;
            Sq_coords->ny = y;
            Sq_coords->maxSize = value;
        }
        x += 1;
        if (x >= *lineLength) {
            x = 1;
            y += 1;
        }
    }
}