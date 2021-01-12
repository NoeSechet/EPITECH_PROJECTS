/*
** EPITECH PROJECT, 2018
** window_Events.c
** File description:
** window_Events
*/

#include "utils.h"

void blackerise_framebuffer(frame_t *buf)
{
    for (uint i = 0; i < (buf->width * buf->height * 4 - 1); i += 1)
        buf->pixels[i] = 0;
}

void black_buff_check(sfEvent event, spritext_t *spritext, char **av)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            av[1][0] = av[1][0] + 1;
            blackerise_framebuffer(spritext->buf);
            sfRenderWindow_clear(spritext->window, sfBlack);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            av[1][0] = av[1][0] - 1;
            blackerise_framebuffer(spritext->buf);
            sfRenderWindow_clear(spritext->window, sfBlack);
        }
}

int analyse_events(char **av, spritext_t *spritext)
{
    sfEvent event;

    if (av[1][0] > '9' && av[1][0] < '0')
        return (0);
    while (sfRenderWindow_pollEvent(spritext->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_destroy(spritext->window);
            return (0);
        }
        black_buff_check(event, spritext, av);
        if (av[1][0] == '0')
            av[1][0] = '4';
        if (av[1][0] == '6')
            av[1][0] = '1';
    }
    return (0);
}

sfRenderWindow *window_create(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode window_mode;

    window_mode.width = width;
    window_mode.height = height;
    window_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(window_mode,
        "window", sfDefaultStyle, NULL);
    return (window);
}