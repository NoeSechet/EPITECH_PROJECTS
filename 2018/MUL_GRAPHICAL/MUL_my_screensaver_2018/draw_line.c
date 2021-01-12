/*
** EPITECH PROJECT, 2018
** draw_line.c
** File description:
** draw_line
*/

#include "utils.h"

void swap_coords(float *coord_a_x, float *coord_b_x)
{
    float temp = 0;

    if (*coord_a_x > *coord_b_x) {
        temp = *coord_a_x;
        *coord_a_x = *coord_b_x;
        *coord_b_x = temp;
    }
}

void draw_line(frame_t *buf, rays_t rays)
{
    float coord_a_x = rays.coords0.x;
    float gradient = (rays.coords1.y - rays.coords0.y) /
        (rays.coords1.x - rays.coords0.x);
    float y_cross = rays.coords0.y - gradient * rays.coords0.x;
    float line_x_coord;
    float line_y_coord;

    swap_coords(&coord_a_x, &rays.coords1.x);
    while (coord_a_x <= rays.coords1.x) {
        line_y_coord = coord_a_x * gradient + y_cross;
        line_x_coord = (line_y_coord - y_cross) / gradient;
        put_pixel(buf, line_x_coord, line_y_coord, rays.color);
        coord_a_x += 1;
    }
}