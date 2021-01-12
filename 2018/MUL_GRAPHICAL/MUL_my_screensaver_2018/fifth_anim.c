/*
** EPITECH PROJECT, 2018
** fifth_anim.c
** File description:
** fifth_anim
*/

#include "utils.h"

void make_a_circle(int x_coord, int y_coord, int radius, spritext_t *spritext)
{
    put_circle(x_coord, y_coord, radius, spritext->buf);
    if (radius > 1) {
        make_a_circle(x_coord + radius, y_coord, radius * 0.5, spritext);
        make_a_circle(x_coord - radius, y_coord, radius * 0.5, spritext);
    }
}

void fifth_anim(main_t *mains, spritext_t *spritext)
{
    (void)mains;
    spritext->time_m = sfClock_getElapsedTime(spritext->clock);
    spritext->time_s = spritext->time_m.microseconds / 1000000;
    make_a_circle(900, 500, 400, spritext);
}