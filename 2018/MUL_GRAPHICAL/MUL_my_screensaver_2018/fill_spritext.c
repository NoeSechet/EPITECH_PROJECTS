/*
** EPITECH PROJECT, 2018
** fill_spritext.c
** File description:
** fill_spritext
*/

#include "utils.h"

frame_t *framebuffer_create(uint width, uint height)
{
    sfUint8 *pixel = malloc(width * height * 4);
    frame_t *buf = malloc(sizeof(frame_t));
    buf->width = width;
    buf->height = height;
    buf->pixels = pixel;
    return (buf);
}

spritext_t *fill_spritext(void)
{
    spritext_t *spritext = malloc(sizeof(spritext_t));
    sfRenderWindow *window = window_create(1800, 1000);
    frame_t *buf = framebuffer_create(1800, 1000);
    sfTexture *text = sfTexture_create(1800, 1000);
    sfSprite *sprite = sfSprite_create();

    spritext->window = window;
    spritext->buf = buf;
    spritext->text = text;
    spritext->sprite = sprite;
    return (spritext);
}