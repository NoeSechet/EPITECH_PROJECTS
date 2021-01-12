/*
** EPITECH PROJECT, 2018
** win_lose_cond.c
** File description:
** win_lose_cond
*/

#include "utils.h"

int win_cond(layer_t *layer)
{
    for (int i = 0; layer->O_tab[i] != NULL; i += 1) {
        if (layer->sky[layer->O_tab[i]->y][layer->O_tab[i]->x] != 'X') {
            return (0);
        }
    }
    return (1);
}

int check_opp_sides(char **sky, coord_t **X_tab, int *counter)
{
    int count = 0;

    if (sky[X_tab[*counter]->y][(X_tab[*counter]->x) + 1] == '#' ||
        sky[X_tab[*counter]->y][(X_tab[*counter]->x) - 1] == '#' ||
        sky[X_tab[*counter]->y][(X_tab[*counter]->x) + 1] == 'X' ||
        sky[X_tab[*counter]->y][(X_tab[*counter]->x) - 1] == 'X')
        count += 1;
    if (sky[(X_tab[*counter]->y) + 1][X_tab[*counter]->x] == '#' ||
        sky[(X_tab[*counter]->y) - 1][X_tab[*counter]->x] == '#' ||
        sky[(X_tab[*counter]->y) + 1][X_tab[*counter]->x] == 'X' ||
        sky[(X_tab[*counter]->y) - 1][X_tab[*counter]->x] == 'X')
        count += 1;
    return (count);
}

void lose_cond(layer_t *layer)
{
    int x_counter = 0;

    detect_x_pos(layer);
    for (int counter = 0; layer->X_tab[counter] != NULL; counter += 1) {
        if (check_opp_sides(layer->sky, layer->X_tab, &counter) == 2)
            x_counter += 1;
    }
    if (x_counter == layer->X_count) {
        exit (1);
    }
}

void win_lose_cond(layer_t *layer)
{
    if (win_cond(layer)) {
        exit(0);
    }
    lose_cond(layer);
}