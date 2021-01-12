/*
** EPITECH PROJECT, 2018
** fourth_anim.c
** File description:
** fourth_anim
*/

#include "utils.h"

void fourth_anim(main_t *mains, spritext_t *spritext)
{
    mains->circles.coords.x += mains->circles.vec.x;
    mains->circles.coords.y += mains->circles.vec.y;
    if (mains->circles.coords.x + mains->circles.radius > 1779 ||
            mains->circles.coords.x - mains->circles.radius < 1)
        mains->circles.vec.x *= -1;
    if (mains->circles.coords.y + mains->circles.radius > 999 ||
            mains->circles.coords.y - mains->circles.radius < 1)
        mains->circles.vec.y *= -1;
    mains->circles.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    draw_circle(spritext->buf, mains->circles);
}