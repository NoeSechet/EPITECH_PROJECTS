/*
** EPITECH PROJECT, 2018
** main_struct.h
** File description:
** main_struct
*/

#include "utils.h"

#ifndef MAIN_STRUCT_H_
#define MAIN_STRUCT_H_

typedef struct framebuffer_struct
{
    uint width;
    uint height;
    sfUint8 *pixels;
} frame_t;

typedef struct spritext_s {
    sfRenderWindow *window;
    frame_t *buf;
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfTime time_m;
    float time_s;
} spritext_t;

typedef struct pixels_s {
    sfVector2i coords;
    sfColor color;
} pixels_t;

typedef struct rays_s {
    sfVector2f coords0;
    sfVector2f coords1;
    sfColor color;
} rays_t;

typedef struct circles_s {
    sfVector2i coords;
    sfVector2i vec;
    int radius;
    sfColor color;
} circles_t;

typedef struct discs_s {
    sfVector2i coords;
    sfVector2i vec;
    int radius;
    sfColor color;
} discs_t;

typedef struct star_s {
    sfVector2i center;
    sfVector2i top_left;
    sfVector2i top_right;
    sfVector2i bot_left;
    sfVector2i bot_right;
    int radius;
    sfColor color;
} star_t;

typedef struct main_s {
    pixels_t pixels;
    rays_t rays;
    circles_t circles;
    discs_t discs;
    star_t star;
} main_t;

typedef struct animations_s {
    char *anim;
    int length;
    void(*function_ptr)(main_t *, spritext_t *);
} anim_t;

pixels_t fill_pixels_struct(void);
rays_t fill_rays_struct(void);
circles_t fill_circles_struct(void);
discs_t fill_discs_struct(void);

#endif /* !MAIN_STRUCT_H_ */