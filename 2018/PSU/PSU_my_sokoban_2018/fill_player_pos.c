/*
** EPITECH PROJECT, 2018
** fill_player_struct.c
** File description:
** fill_player_struct
*/

#include "utils.h"

void check_coord_p_xcoords(char **sky, player_t *player, int *y)
{
    for (int x = 0; sky[*y][x] != '\n'; x += 1) {
        if (sky[*y][x] == 'P') {
            player->pos.x = x;
            player->pos.y = *y;
        }
    }
}

void detect_player_pos(char **sky, player_t *player)
{
    for (int y = 0; sky[y] != NULL; y += 1)
        check_coord_p_xcoords(sky, player, &y);
}

void fill_player_pos(layer_t *layer, player_t *player)
{
    detect_player_pos(layer->sky, player);
    detect_o_pos(layer);
}