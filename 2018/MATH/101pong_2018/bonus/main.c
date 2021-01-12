/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "bonus.h"

sfRenderWindow *window_create(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode window_mode;

    window_mode.width = width;
    window_mode.height = height;
    window_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(window_mode,
        "pong_window", sfDefaultStyle, NULL);
    return (window);
}

int analyse_events(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (0);
        }
    }
    return (0);
}

void draw_bat(sfRenderWindow *window, sfVector2f *bat_coord)
{
    sfTexture *bat_txt;
    sfSprite *bat_spr;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && bat_coord->x > 3)
        bat_coord->x = bat_coord->x - 12;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && bat_coord->x < 810)
        bat_coord->x = bat_coord->x + 12;
    bat_txt = sfTexture_createFromFile("sprite/bat.jpg", NULL);
    bat_spr = sfSprite_create();
    sfSprite_setPosition(bat_spr, *bat_coord);
    sfSprite_setTexture(bat_spr, bat_txt, sfTrue);
    sfRenderWindow_drawSprite(window, bat_spr, NULL);
    if (!(sfRenderWindow_isOpen(window))) {
        sfTexture_destroy(bat_txt);
        sfSprite_destroy(bat_spr);
    }
}

int main(void)
{
    sfRenderWindow *window = window_create(950, 950);
    sfVector2f bat_coord = fill_vector(475 - 69, 800);
    sfVector2f ball_coord = fill_vector(475, 30);
    sfVector2f ball_velocity = fill_vector(0, 5);
    brick_t **brick = fill_wall();

    sfRenderWindow_setFramerateLimit(window, 42);
    while (sfRenderWindow_isOpen(window)) {

        sfRenderWindow_clear(window, sfBlack);
        draw_bat(window, &bat_coord);
        draw_ball(window, &ball_coord, &ball_velocity, bat_coord);
        draw_wall(window, &ball_coord, &ball_velocity, brick);
        analyse_events(window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}