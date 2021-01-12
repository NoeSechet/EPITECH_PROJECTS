/*
** EPITECH PROJECT, 2018
** first_anim.c
** File description:
** first_anim
*/

#include "utils.h"

void first_anim(main_t *mains, spritext_t *spritext)
{
    sfRenderWindow_setFramerateLimit(spritext->window, 10000);
    mains->pixels.coords.x = rand() % 1800;
    mains->pixels.coords.y = rand() % 1000;
    mains->pixels.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    put_pixel(spritext->buf, mains->pixels.coords.x, mains->pixels.coords.y,
        mains->pixels.color);
}