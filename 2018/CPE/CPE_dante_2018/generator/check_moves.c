/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** check_moves.c
*/

#include "utils_dante.h"

int check_right(maze_t *maze)
{
    int column = 0;

    if ((column = current_column(maze->current_pos, maze->width))
    == maze->width) {
        return (-1);
    }
    if (maze->map[maze->current_pos + 2] == '1') {
        return (1);
    }
    return (-1);
}

int check_left(maze_t *maze)
{
    int column = 0;

    if ((column = current_column(maze->current_pos, maze->width)) == 1) {
        return (-1);
    }
    if (maze->map[maze->current_pos - 2] == '1') {
        return (2);
    }
    return (-1);
}

int check_down(maze_t *maze)
{
    int line = current_line(maze->current_pos, maze->width + 1);

    if (line == maze->height) {
        return (-1);
    }
    if (maze->map[maze->current_pos + (maze->width * 2 + 2)] == '1') {
        return (3);
    }
    return (-1);
}

int check_up(maze_t *maze)
{
    int line = 0;

    if ((line = current_line(maze->current_pos, maze->width + 1)) < 2) {
        return (-1);
    }
    if (maze->map[maze->current_pos - (maze->width * 2 + 2)] == '1') {
        return (4);
    }
    return (-1);
}