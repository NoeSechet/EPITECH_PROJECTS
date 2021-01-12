/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include "utils_dante.h"

int *init_pf(int height, int width)
{
    int total = height * width;
    int *PF = malloc(sizeof(int) * total);

    for (int it = 0; it < total; it++) {
        if (it == 0)
            PF[it] = 0;
        else
            PF[it] = -2;
    }
    return (PF);
}

void is_correct_char(char c)
{
    if (c != 'X' && c != '*' && c != '\n') exit(84);
}

void is_correct_format(char *maze, int width)
{
    int j = 1;

    for (int i = 0; maze[i] != '\0'; i++) {
        if (maze[i] == '\n') {
            if (j -1 != width) {
                exit(84);
            }
            j = 0;
        }
        j += 1;
        is_correct_char(maze[i]);
    }
    if (j -1 != width && j != 1) {
        exit(84);
    }
}

dijkstra_t *init_dijkstra(char *maze)
{
    dijkstra_t *dij = malloc(sizeof(dijkstra_t));

    dij->width = get_width(maze);
    dij->height = get_height(maze);
    dij->total = dij->width * dij->height;
    dij->total >= 9 ? 0 : exit(84);
    is_correct_format(maze, dij->width);
    dij->PF = init_pf(dij->height, dij->width);
    dij->COST = 1;
    return (dij);
}