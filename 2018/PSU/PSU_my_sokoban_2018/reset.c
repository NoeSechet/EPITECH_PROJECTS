/*
** EPITECH PROJECT, 2018
** check_winning_condiitons.c
** File description:
** check_winning_condiitons
*/

#include "utils.h"

void check_sky_x(layer_t *layer, int *sky_y)
{
    for (int sky_x = 0; layer->sky[*sky_y][sky_x] != '\0'; sky_x += 1) {
        if (layer->sky[*sky_y][sky_x] == 'X' ||
                layer->sky[*sky_y][sky_x] == 'P')
            layer->sky[*sky_y][sky_x] = ' ';
    }
}

void check_save_x(layer_t *layer, player_t *player, int *save_y)
{
    for (int save_x = 0; layer->save[*save_y][save_x] != '\0'; save_x += 1) {
        if (layer->save[*save_y][save_x] == 'X')
            layer->sky[*save_y][save_x] = 'X';
        if (layer->save[*save_y][save_x] == 'P') {
            layer->sky[*save_y][save_x] = 'P';
            player->pos.x = save_x;
            player->pos.y = *save_y;
        }
    }
}

void replace_sky_x(layer_t *layer, player_t *player)
{
    for (int save_y = 0; layer->save[save_y] != NULL; save_y += 1)
        check_save_x(layer, player, &save_y);
}

void reset_map(layer_t *layer, player_t *player)
{
    for (int sky_y = 0; layer->sky[sky_y] != NULL; sky_y += 1)
        check_sky_x(layer, &sky_y);
    replace_sky_x(layer, player);
}