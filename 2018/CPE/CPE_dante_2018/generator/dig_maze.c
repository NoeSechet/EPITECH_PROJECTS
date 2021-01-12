/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** dig_maze.c
*/

#include "utils_dante.h"

int convert_crosses_into_stars(maze_t *maze, int new_pos)
{
    switch (new_pos) {
        case 1: maze->map[maze->current_pos + 1] = '*';
                maze->map[maze->current_pos + 2] = '*';
                maze->current_pos = maze->current_pos + 2;
                break;
        case 2: maze->map[maze->current_pos - 1] = '*';
                maze->map[maze->current_pos - 2] = '*';
                maze->current_pos = maze->current_pos - 2;
                break;
        case 3: maze->map[maze->current_pos + (maze->width * 1 + 1)] = '*';
                maze->map[maze->current_pos + (maze->width * 2 + 2)] = '*';
                maze->current_pos = maze->current_pos + (maze->width * 2 + 2);
                break;
        case 4: maze->map[maze->current_pos - (maze->width * 1 + 1)] = '*';
                maze->map[maze->current_pos - (maze->width * 2 + 2)] = '*';
                maze->current_pos = maze->current_pos - (maze->width * 2 + 2);
                break;
        default: break;
    }
    return (1);
}

int dig_maze(maze_t *maze)
{
    int new_pos = 0;
    maze->map[new_pos] = '*';

    for (int i = 0; maze->stack_list->size > 0; i += 1) {
        new_pos = valid_moves(maze);
        if (new_pos == 0) {
            remove_move(maze->stack_list);
            if (maze->stack_list->end != NULL)
                maze->current_pos = maze->stack_list->end->pos;
        } else {
            convert_crosses_into_stars(maze, new_pos);
            insert_move(maze->stack_list, maze->current_pos);
        }
    }
    return (1);
}