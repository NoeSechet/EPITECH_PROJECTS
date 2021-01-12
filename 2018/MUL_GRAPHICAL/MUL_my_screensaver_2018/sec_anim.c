/*
** EPITECH PROJECT, 2018
** sec_anim.c
** File description:
** sec_anim
*/

#include "utils.h"

void sec_anim(main_t *mains, spritext_t *spritext)
{
    mains->rays.coords0.x = rand() % 1800;
    mains->rays.coords0.y = rand() % 1000;
    mains->rays.coords1.x = rand() % 1800;
    mains->rays.coords1.y = rand() % 1000;
    mains->rays.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    draw_line(spritext->buf, mains->rays);
}