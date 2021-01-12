/*
** EPITECH PROJECT, 2019
** print_maps.c
** File description:
** print_maps.c
*/

#include "include/utils.h"

void print_maps(char **map_player, char **map_enemy)
{
    my_printf("\nmy positions:\n");
    for (int i = 0; map_player[i] != NULL; i++)
        my_printf("%s\n", map_player[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0; map_player[i] != NULL; i++)
        my_printf("%s\n", map_enemy[i]);
}