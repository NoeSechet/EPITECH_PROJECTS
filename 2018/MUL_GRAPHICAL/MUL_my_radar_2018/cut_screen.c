/*
** EPITECH PROJECT, 2019
** cut_screen.c
** File description:
** cut_screen.c
*/

#include "utils.h"

air_list_t *fill_tab_list(air_list_t *tab_list, aircraft_t *temp_plane)
{
    aircraft_t *plane = malloc(sizeof(aircraft_t));
    plane->id = 0;
    plane->a = temp_plane->a;
    plane->b = temp_plane->b;
    plane->pps = temp_plane->pps;
    plane->t_off = temp_plane->t_off;
    plane->shape = temp_plane->shape;
    plane->collide = temp_plane->collide;
    plane->previous = NULL;
    plane->next = NULL;

    if (tab_list->length == 0) {
        tab_list->start = plane;
        tab_list->end = plane;
    } else {
        plane->previous = tab_list->end;
        tab_list->end->next = plane;
        tab_list->end = plane;
    }
    tab_list->length += 1;
    return (tab_list);
}

air_list_t **cut_screen(int size[2], int w, int h, air_list_t *air_list)
{
    air_list_t **tab_list = malloc(sizeof(air_list_t *) * (w * h + 1));
    int width = size[0] / w;
    int height = size[1] / h;
    int x = 0;
    int y = 0;

    for (int i = 0; i < w * h; i += 1)
        tab_list[i] = new_air_list();
    for (aircraft_t *temp = air_list->start; temp != NULL; temp = temp->next) {
        x = temp->a.x / width;
        y = temp->a.y / height;
        if (x < w && y < h) {
            tab_list[x + y * w] = fill_tab_list(tab_list[x + y * w], temp);
        }
    }
    tab_list[w + h] = NULL;
    return (tab_list);
}