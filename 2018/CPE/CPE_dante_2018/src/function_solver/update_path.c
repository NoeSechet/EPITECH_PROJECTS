/*
** EPITECH PROJECT, 2019
** update
** File description:
** update$
*/

#include "utils_dante.h"

int norme_draw(dijkstra_t *dij, char *maze, int *P, int *M)
{
    int line = current_line(*P, dij->width) -1;

    if (line > 0 && dij->PF[*P - dij->width] == dij->COST - 1) {
        *P = *P - dij->width;
        *M = *M - (dij->width + 1);
        if (maze[*M] == '\n') *M = *M - 1;
        maze[*M] = 'o';
        return (1);
    }
    if (line < dij->height - 1 && dij->PF[*P + dij->width] == dij->COST - 1) {
        *P = *P + dij->width;
        *M = *M + (dij->width + 1);
        if (maze[*M] == '\n') *M = *M + 1;
        maze[*M] = 'o';
        return (1);
    }
    return (0);
}

void draw_path(dijkstra_t *dij, char *maze, int *P, int *M)
{
    int col = current_column(*P, dij->width) - 1;

    if (norme_draw(dij, maze, P, M) == 1) return;
    if (col < dij->width - 1 && dij->PF[*P + 1] == dij->COST - 1) {
        *P = *P + 1;
        *M = *M + 1;
        if (maze[*M] == '\n') *M = *M + 1;
        maze[*M] = 'o';
        return;
    }
    if (col > 0 && dij->PF[*P - 1] == dij->COST - 1) {
        *P = *P - 1;
        *M = *M - 1;
        if (maze[*M] == '\n') *M = *M - 1;
        maze[*M] = 'o';
        return;
    }
}

void update_path(dijkstra_t *dij, char *maze)
{
    int P = dij->total - 1;
    int M = strlen(maze) - 1;
    dij->COST = dij->PF[P];

    if (maze[M] == '\n') M = M - 1;
    maze[M] = 'o';
    while (P != 0) {
        draw_path(dij, maze, &P, &M);
        dij->COST = dij->COST -1;
    }
}