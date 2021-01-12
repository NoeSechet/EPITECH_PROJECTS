/*
** EPITECH PROJECT, 2019
** win_conditions.c
** File description:
** win_conditions.c
*/

#include "include/utils.h"

int win_conditions(char **map_player_1, char **map_player_2)
{
    int player_1_counter = 0;
    int player_2_counter = 0;

    for (int i = 0; map_player_2[i] != NULL; i += 1)
        for (int j = 0; map_player_2[i][j] != '\0'; j += 1) {
            if (map_player_1[i][j] == 'x')
                player_1_counter += 1;
            if (map_player_2[i][j] == 'x')
                player_2_counter += 1;
    }
    if (player_1_counter == 14) {
        my_printf("\nEnemy won\n");
        return (1);
    }
    if (player_2_counter == 14) {
        my_printf("\nI won\n");
        return (0);
    }
    return (2);
}