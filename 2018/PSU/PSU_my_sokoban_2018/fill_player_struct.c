/*
** EPITECH PROJECT, 2018
** fill_player_layer_struct.c
** File description:
** fill_player_layer_struct
*/

#include "utils.h"

player_t *fill_player_struct(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->pos.x = 0;
    player->pos.y = 0;
    player->nbr_line = 0;
    player->line_max_length = 0;
    return (player);
}