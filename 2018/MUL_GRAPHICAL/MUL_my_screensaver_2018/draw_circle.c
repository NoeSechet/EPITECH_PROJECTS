/*
** EPITECH PROJECT, 2018
** draw_circle
** File description:
** draw_circle
*/

#include "utils.h"

void check_circle_coords(frame_t *buf, int x, int y, circles_t circles)
{
    if (sqrt(pow((circles.coords.x - x), 2) + pow((circles.coords.y - y), 2)) /
    circles.radius < 1.02 && sqrt(pow((circles.coords.x - x), 2) +
    pow((circles.coords.y - y), 2)) / circles.radius > 0.98) {
        put_pixel(buf, x, y, circles.color);
    }
}

void draw_circle(frame_t *buf, circles_t circles)
{
    for (int x = circles.coords.x - circles.radius - 10; x < circles.coords.x +
        circles.radius + 10; x += 1) {
        for (int y = circles.coords.y - circles.radius - 10; y <
                circles.coords.y + circles.radius + 10; y += 1)
            check_circle_coords(buf, x, y, circles);
    }
}

void check_put_circle(frame_t *buf, sfVector2i vec, sfVector2i pos, int radius)
{
    if (sqrt(pow((pos.x - vec.x), 2) + pow((pos.y - vec.y), 2))
            / radius < 1.005 &&
            sqrt(pow((pos.x - vec.x), 2) + pow((pos.y - vec.y), 2))
                / radius > 0.995) {
        put_pixel(buf, vec.x, vec.y, sfColor_fromInteger(rand() % 0xFFFFFF));
    }
}

void put_circle(int coord_x, int coord_y, int radius, frame_t *buf)
{
    sfVector2i vec;
    sfVector2i coords;
    coords.x = coord_x;
    coords.y = coord_y;

    for (vec.x = coords.x - radius - 10; vec.x < coords.x +
            radius + 10; vec.x += 1) {
        for (vec.y = coords.y - radius - 10; vec.y < coords.y +
                radius + 10; vec.y += 1)
            check_put_circle(buf, vec, coords, radius);
    }
}