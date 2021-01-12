/*
** EPITECH PROJECT, 2018
** fill_layer.c
** File description:
** fill_layer
*/

#include "utils.h"

void cpy_sky(char *sky, char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '#' || line[i] == 'P' || line[i] == 'X' ||
                line[i] == '\n')
            sky[i] = line[i];
        else
            sky[i] = ' ';
        i += 1;
    }
}

void cpy_map(char *map, char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] == '#' || line[i] == 'O' || line[i] == '\n')
            map[i] = line[i];
        else
            map[i] = ' ';
        i += 1;
    }
}

void cpy_save(char *save, char *line)
{
    int i = 0;

    while (line[i] != '\0') {
        save[i] = line[i];
        i += 1;
    }
}

void fill_layer(char *line, layer_t *layer, int s)
{
    cpy_map(layer->map[s], line);
    cpy_sky(layer->sky[s], line);
    cpy_save(layer->save[s], line);
}