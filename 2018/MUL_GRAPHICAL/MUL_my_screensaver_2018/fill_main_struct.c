/*
** EPITECH PROJECT, 2018
** fill_main_struct.c
** File description:
** fill_main_struct
*/

#include "utils.h"

pixels_t fill_pixels_struct(void)
{
    pixels_t pixels;

    pixels.coords.x = my_random(10, 1790);
    pixels.coords.y = my_random(10, 790);
    pixels.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    return (pixels);
}

rays_t fill_rays_struct(void)
{
    rays_t rays;

    rays.coords0.x = my_random(10, 1790);
    rays.coords0.y = my_random(10, 790);
    rays.coords1.x = my_random(10, 1790);
    rays.coords1.y = my_random(10, 790);
    rays.color = sfColor_fromInteger(rand() % 0xFFFFFF);
    return (rays);
}

circles_t fill_circles_struct(void)
{
    circles_t circles;

    circles.coords.x = 200;
    circles.coords.y = 200;
    circles.vec.x = 5;
    circles.vec.y = 5;
    circles.radius = 20;
    circles.color = sfWhite;
    return (circles);
}

discs_t fill_discs_struct(void)
{
    discs_t discs;

    discs.coords.x = 200;
    discs.coords.y = 200;
    discs.vec.x = 5;
    discs.vec.y = 5;
    discs.radius = 20;
    discs.color = sfWhite;
    return (discs);
}

main_t *fill_main_struct(void)
{
    pixels_t pixels = fill_pixels_struct();
    rays_t rays = fill_rays_struct();
    circles_t circles = fill_circles_struct();
    discs_t discs = fill_discs_struct();
    main_t *mains = malloc(sizeof(main_t));

    mains->pixels = pixels;
    mains->rays = rays;
    mains->circles = circles;
    mains->discs = discs;
    return (mains);
}