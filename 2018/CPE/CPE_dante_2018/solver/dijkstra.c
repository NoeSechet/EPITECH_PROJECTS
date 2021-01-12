/*
** EPITECH PROJECT, 2019
** dijkstra
** File description:
** dijkstra
*/

#include "utils_dante.h"

void print_pf(int *PF, int width, int height)
{
    int n = 0;

    for (int it = 0; it < width * height; it++) {
        printf("%d", PF[it]);
        n += 1;
        if (n == width) {
            printf("\n");
            n = 0;
        }
    }
}

void pathfinding(dijkstra_t *dij, char *maze, int P, int M)
{
    int line = current_line(P, dij->width) -1;
    int col = current_column(P, dij->width) - 1;

    if (line > 0 && maze[M - (dij->width + 1)] == '*' &&
    dij->PF[P - dij->width] == -2) {
        dij->PF[P - dij->width] = dij->COST;
    }
    if (line < dij->height - 1 && maze[M + (dij->width + 1)] == '*' &&
    dij->PF[P + dij->width] == -2) {
        dij->PF[P + dij->width] = dij->COST;
    }
    if (col < dij->width -1 && maze[M + 1] == '*' && dij->PF[P + 1] == -2) {
        dij->PF[P + 1] = dij->COST;
    }
    if (col > 0 && maze[M - 1] == '*' && dij->PF[P - 1] == -2) {
        dij->PF[P - 1] = dij->COST;
    }
}

void is_end(int total, char *maze)
{
    if (maze[total -1] == '\n') total = total - 1;
    if (maze[total - 1] == 'X') exit(84);
}

void display_maze_solved(char *maze, int total)
{
    if (maze[total- 1] == '\n')
        write(1, maze, total - 1);
    else
        write(1, maze, total);
}

void dijkstra(char *maze)
{
    dijkstra_t *dij = init_dijkstra(maze);
    int total = strlen(maze);

    is_end(total, maze);
    while (1) {
        for (int M = 0, P = 0; P < dij->total; P++, M++) {
            if (maze[M] == '\n')
                M += 1;
            if (dij->PF[P] != dij->COST && dij->PF[P] != -2)
                pathfinding(dij, maze, P, M);
        }
        if (dij->PF[dij->total - 1] != -2)
            break;
        dij->COST += 1;
    }
    update_path(dij, maze);
    display_maze_solved(maze, total);
}