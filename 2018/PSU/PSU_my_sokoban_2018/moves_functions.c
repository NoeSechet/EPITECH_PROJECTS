/*
** EPITECH PROJECT, 2018
** moves_functions.c
** File description:
** moves_functions
*/

#include "utils.h"

void moves_up(layer_t *layer, player_t *player)
{
    if (layer->map[player->pos.y - 1][player->pos.x] != '#' &&
    layer->sky[player->pos.y - 1][player->pos.x] != 'X') {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.y -= 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
    } else if (layer->sky[player->pos.y - 1][player->pos.x] == 'X' &&
    (layer->sky[player->pos.y - 2][player->pos.x] == ' ' ||
    layer->map[player->pos.y - 2][player->pos.x] == 'O')) {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.y -= 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
        layer->sky[player->pos.y - 1][player->pos.x] = 'X';
    }
}

void moves_down(layer_t *layer, player_t *player)
{
    if (layer->map[player->pos.y + 1][player->pos.x] != '#' &&
    layer->sky[player->pos.y + 1][player->pos.x] != 'X') {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.y += 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
    } else if (layer->sky[player->pos.y + 1][player->pos.x] == 'X' &&
    (layer->sky[player->pos.y + 2][player->pos.x] == ' ' ||
    layer->map[player->pos.y + 2][player->pos.x] == 'O')) {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.y += 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
        layer->sky[player->pos.y + 1][player->pos.x] = 'X';
    }
}

void moves_right(layer_t *layer, player_t *player)
{
    if (layer->map[player->pos.y][player->pos.x + 1] != '#' &&
    layer->sky[player->pos.y][player->pos.x + 1] != 'X') {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.x += 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
    } else if (layer->sky[player->pos.y][player->pos.x + 1] == 'X' &&
    (layer->sky[player->pos.y][player->pos.x + 2] == ' ' ||
    layer->map[player->pos.y][player->pos.x + 2] == 'O')) {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.x += 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
        layer->sky[player->pos.y][player->pos.x + 1] = 'X';
    }
}

void moves_left(layer_t *layer, player_t *player)
{
    if (layer->map[player->pos.y][player->pos.x - 1] != '#' &&
    layer->sky[player->pos.y][player->pos.x - 1] != 'X') {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.x -= 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
    } else if (layer->sky[player->pos.y][player->pos.x - 1] == 'X' &&
    (layer->sky[player->pos.y][player->pos.x - 2] == ' ' ||
    layer->map[player->pos.y][player->pos.x - 2] == 'O')) {
        layer->sky[player->pos.y][player->pos.x] = ' ';
        player->pos.x -= 1;
        layer->sky[player->pos.y][player->pos.x] = 'P';
        layer->sky[player->pos.y][player->pos.x - 1] = 'X';
    }
}