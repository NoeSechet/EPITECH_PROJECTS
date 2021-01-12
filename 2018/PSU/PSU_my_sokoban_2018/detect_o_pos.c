/*
** EPITECH PROJECT, 2018
** detect_O_pos.c
** File description:
** detect_O_pos
*/

#include "utils.h"

void check_coords_o(layer_t *layer, int *map_y, int *o_counter)
{
    int map_x = 0;

    while (layer->map[*map_y][map_x] != '\n') {
        if (layer->map[*map_y][map_x] == 'O') {
            layer->O_tab[*o_counter]->x = map_x;
            layer->O_tab[*o_counter]->y = *map_y;
            *o_counter += 1;
        }
        map_x += 1;
    }
}

void detect_o_pos(layer_t *layer)
{
    int o_counter = 0;
    layer->O_tab = malloc(sizeof(coord_t *) * layer->O_count + 1);
    layer->O_tab[layer->O_count] = NULL;

    for (int i = 0; i < layer->O_count; i += 1) {
        layer->O_tab[i] = malloc(sizeof(coord_t));
        layer->O_tab[i]->x = 0;
        layer->O_tab[i]->y = 0;
    }
    for (int map_y = 0; layer->map[map_y] != NULL; map_y += 1)
        check_coords_o(layer, &map_y, &o_counter);
}