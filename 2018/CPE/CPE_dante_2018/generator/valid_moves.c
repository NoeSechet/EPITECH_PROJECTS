/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** valid_moves.c
*/

#include "utils_dante.h"

int valid_moves(maze_t *maze)
{
    int *possible_pos = NULL;
    int tab[4] = {0, 0, 0, 0};
    int index = 0;
    int res = 0;

    (tab[0] = check_right(maze)) != -1 ? index += 1 : 0;
    (tab[1] = check_left(maze)) != -1 ? index += 1 : 0;
    (tab[2] = check_down(maze)) != -1 ? index += 1 : 0;
    (tab[3] = check_up(maze)) != -1 ? index += 1 : 0;
    if (index == 0) return (0);
    possible_pos = malloc(sizeof(int) * index);
    for (int i = 0, j = 0; i < 4; i += 1)
        if (tab[i] != -1) {
            possible_pos[j] = tab[i];
            j += 1;
        }
    res = possible_pos[(rand() % index)];
    return (res);
}