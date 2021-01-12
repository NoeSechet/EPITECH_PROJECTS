/*
** EPITECH PROJECT, 2018
** fill_aircraft_list.c
** File description:
** fill_aircraft_list.c
*/

#include "utils.h"

air_list_t *fill_aircraft_list(air_list_t *air_list, int *decomp_info,
void *rect)
{
    aircraft_t *plane = malloc(sizeof(aircraft_t));
    plane->id = 0;
    plane->a = (sfVector2f){(decomp_info[0]), (decomp_info[1])};
    plane->b = (sfVector2f){(decomp_info[2]), (decomp_info[3])};
    plane->pps = decomp_info[4];
    plane->t_off = decomp_info[5];
    plane->shape = rect;
    plane->collide = 0;
    plane->previous = NULL;
    plane->next = NULL;

    if (air_list->length == 0) {
        air_list->start = plane;
        air_list->end = plane;
    } else {
        plane->previous = air_list->end;
        air_list->end->next = plane;
        air_list->end = plane;
    }
    air_list->length += 1;
    return (air_list);
}