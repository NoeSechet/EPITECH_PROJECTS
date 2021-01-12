/*
** EPITECH PROJECT, 2019
** init_maze
** File description:
** init_maze
*/

#include "utils_dante.h"

char *init_maze(int x, int y)
{
    char *maze = malloc(sizeof(char) * (x * y + y + 1));;

    for (int i = 0, j = 0, index_n = 0; i < x * y + y; i += 1)
        if (index_n == x) {
            maze[i] = '\n';
            index_n = 0;
        } else if ((current_line(j, x) % 2 == 1) &&
        (current_column(j, x) % 2 == 1)) {
            maze[i] = '1';
            index_n += 1;
            j += 1;
        } else {
            maze[i] = 'X';
            index_n += 1;
            j += 1;
        }
    maze[x * y + y - 1] = '\0';
    return (maze);
}

char rand_char(void)
{
    int i = rand() % 2;
    return (i == 1 ? 'X' : '*');
}

char *init_imperf_maze(int x, int y)
{
    char *maze = malloc(sizeof(char) * (x * y + y + 1));;

    for (int i = 0, j = 0, index_n = 0; i < x * y + y; i += 1)
        if (index_n == x) {
            maze[i] = '\n';
            index_n = 0;
        } else if ((current_line(j, x) % 2 == 1) &&
        (current_column(j, x) % 2 == 1)) {
            maze[i] = '1';
            index_n += 1;
            j += 1;
        } else {
            maze[i] = rand_char();
            index_n += 1;
            j += 1;
        }
    maze[x * y + y - 1] = '\0';
    return (maze);
}

maze_t *init_maze_struct(int x, int y, int perf_imperf)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (perf_imperf == 1)
        maze->map = init_maze(x, y);
    else
        maze->map = init_imperf_maze(x, y);
    maze->stack_list = init_stack_list();
    maze->width = x;
    maze->height = y;
    maze->current_pos = 0;

    return (maze);
}