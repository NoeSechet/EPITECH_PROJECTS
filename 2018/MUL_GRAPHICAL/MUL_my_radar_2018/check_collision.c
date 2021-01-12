/*
** EPITECH PROJECT, 2019
** check_collision.c
** File description:
** check_collision.c
*/

#include "utils.h"

int square_collision_counter(sfVector2f *coord1, float pos[2])
{
    if (pos[0] >= coord1->x && pos[0] <= coord1->x + 20 && pos[1] >=
        coord1->y && pos[1] <= coord1->y + 20) {
        return (1);
        }
    return (0);
}

int planes_collide_veri(sfVector2f *coord1, sfVector2f *coord2)
{
    int count = 0;

    count += square_collision_counter(coord1, (float[2]){coord2->x,
        coord2->y});
    count += square_collision_counter(coord1, (float[2]){coord2->x + 20,
        coord2->y});
    count += square_collision_counter(coord1, (float[2]){coord2->x,
        coord2->y + 20});
    count += square_collision_counter(coord1, (float[2]){coord2->x + 20,
        coord2->y + 20});
    return (count);
}

void check_collision(air_list_t *air_list)
{
    for (aircraft_t *plane1 = air_list->start, *plane2 = air_list->start;
    plane1 != NULL; plane1 = plane1->next, plane2 = air_list->start)
        for (; plane2 != NULL; plane2 = plane2->next)
            if (plane1 != plane2)
                (planes_collide_veri(&plane1->a, &plane2->a) > 0) ?
                    remove_temp(air_list, plane1),
                    remove_temp(air_list, plane2) : 0;
}