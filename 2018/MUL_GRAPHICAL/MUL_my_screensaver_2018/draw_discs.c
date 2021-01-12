/*
** EPITECH PROJECT, 2018
** draw_circle.c
** File description:
** draw_circle
*/

#include "utils.h"

void check_disc_coords(frame_t *buf, int x, int y, discs_t discs)
{
    if (((pow((x - discs.coords.x), 2)) + pow((y - discs.coords.y), 2))
            <= pow(discs.radius, 2))
        put_pixel(buf, x, y, discs.color);
}

void draw_discs(frame_t *buf, discs_t discs)
{
    for (int x = discs.coords.x - discs.radius; x < discs.coords.x +
        discs.radius; x += 1) {
        for (int y = discs.coords.y - discs.radius; y < discs.coords.y +
                discs.radius; y += 1)
            check_disc_coords(buf, x, y, discs);
    }
}