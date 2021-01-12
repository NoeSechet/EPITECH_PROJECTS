/*
** EPITECH PROJECT, 2018
** third_anim.c
** File description:
** third_anim
*/

#include "utils.h"

void fill_black_discs(main_t *mains, spritext_t *spritext)
{
    int coord_x = 200;
    int coord_y = 200;
    int vec_x = 5;
    int vec_y = 5;
    coord_x += vec_x;
    coord_y += vec_y;
    if (coord_x + mains->discs.radius > 1779 ||
            coord_x - mains->discs.radius < 1)
        vec_x *= -1;
    if (coord_y + mains->discs.radius > 1779 ||
            coord_y - mains->discs.radius < 1)
        vec_y *= -1;
    mains->discs.color = sfColor_fromInteger(0x000000);
    draw_discs(spritext->buf, mains->discs);
}

void draw_anim(main_t *mains, spritext_t *spritext)
{
    mains->discs.coords.x += mains->discs.vec.x;
    mains->discs.coords.y += mains->discs.vec.y;
    if (mains->discs.coords.x + mains->discs.radius > 1779 ||
            mains->discs.coords.x - mains->discs.radius < 1)
        mains->discs.vec.x *= -1;
    if (mains->discs.coords.y + mains->discs.radius > 999 ||
            mains->discs.coords.y - mains->discs.radius < 1)
        mains->discs.vec.y *= -1;
    mains->discs.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    draw_discs(spritext->buf, mains->discs);
}

void third_anim(main_t *mains, spritext_t *spritext)
{
    spritext->time_m = sfClock_getElapsedTime(spritext->clock);
    spritext->time_s = spritext->time_m.microseconds / 1000000;
    if (spritext->time_s > 10)
        fill_black_discs(mains, spritext);
    if (spritext->time_s > 20)
        sfClock_restart(spritext->clock);
    else
        draw_anim(mains, spritext);
}