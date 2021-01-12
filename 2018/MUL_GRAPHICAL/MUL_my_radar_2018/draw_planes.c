/*
** EPITECH PROJECT, 2019
** draw_planes.c
** File description:
** draw_planes.c
*/

#include "utils.h"

sfVector2f update_position(aircraft_t *plane, sfClock *my_clock,
sfClock *my_clock_launch, float *dspl)
{
    sfInt64 second = sfClock_getElapsedTime(my_clock).microseconds * 1000000;
    sfInt64 launch_signal =
    sfClock_getElapsedTime(my_clock_launch).microseconds / 1000000;
    if (second > 0.5 && launch_signal > plane->t_off) {
        plane->a.x += dspl[0] / 2;
        plane->a.y += dspl[1] / 2;
        sfClock_restart(my_clock);
    }
    return (plane->a);
}

void draw_rectangle(sfRenderWindow *window, aircraft_t *plane,
sfClock *my_clock, sfClock *my_clock_launch)
{
    double distance = (sqrt((plane->b.x - plane->a.x) * (plane->b.x -
        plane->a.x) + (plane->b.y - plane->a.y) * (plane->b.y - plane->a.y)));
    float dspl_x = ((plane->b.x - plane->a.x) / distance) * plane->pps;
    float dspl_y = ((plane->b.y - plane->a.y) / distance) * plane->pps;

    if (distance > plane->pps) {
        sfRectangleShape_setPosition(plane->shape, update_position(plane,
        my_clock, my_clock_launch, (float[2]){dspl_x, dspl_y}));
    } else {
        sfRectangleShape_setPosition(plane->shape, plane->a);
    }
    if (plane->collide == 0) {
        sfRectangleShape_setFillColor(plane->shape, sfBlack);
        sfRenderWindow_drawRectangleShape(window, plane->shape, NULL);
    }
}

void draw_planes(sfRenderWindow *window, air_list_t *air_list,
sfClock *my_clock, sfClock *my_clock_launch)
{
    if (air_list->start != NULL)
        for (aircraft_t *temp = air_list->start; temp != NULL;
            temp = temp->next)
            draw_rectangle(window, temp, my_clock, my_clock_launch);
}