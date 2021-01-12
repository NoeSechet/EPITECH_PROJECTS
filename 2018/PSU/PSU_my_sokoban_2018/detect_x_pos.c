/*
** EPITECH PROJECT, 2018
** detect_x_pos.c
** File description:
** detect_x_pos
*/

#include "utils.h"

void check_coords_x(layer_t *layer, int *sky_y, int *x_counter)
{
    int map_x = 0;

    while (layer->sky[*sky_y][map_x] != '\n') {
        if (layer->sky[*sky_y][map_x] == 'X') {
            layer->X_tab[*x_counter]->x = map_x;
            layer->X_tab[*x_counter]->y = *sky_y;
            *x_counter += 1;
        }
        map_x += 1;
    }
}

void detect_x_pos(layer_t *layer)
{
    int x_counter = 0;
    layer->X_tab = malloc(sizeof(coord_t *) * layer->X_count + 1);
    layer->X_tab[layer->X_count] = NULL;

    for (int i = 0; i < layer->X_count; i += 1) {
        layer->X_tab[i] = malloc(sizeof(coord_t));
        layer->X_tab[i]->x = 0;
        layer->X_tab[i]->y = 0;
    }
    for (int sky_y = 0; layer->sky[sky_y] != NULL; sky_y += 1)
        check_coords_x(layer, &sky_y, &x_counter);
}