/*
** EPITECH PROJECT, 2018
** my_put_pixel.c
** File description:
** my_put_pixel
*/

#include "utils.h"

void put_pixel(frame_t *buf, int x, int y, sfColor color)
{
    buf->pixels[(buf->width * y + x) * 4] = color.r;
    buf->pixels[(buf->width * y + x) * 4 + 1] = color.g;
    buf->pixels[(buf->width * y + x) * 4 + 2] = color.b;
    buf->pixels[(buf->width * y + x) * 4 + 3] = color.a;
}