/*
** EPITECH PROJECT, 2019
** utils_dante.h
** File description:
** utils_dante.h
*/

#ifndef UTILS_DANTE_H_
#define UTILS_DANTE_H_

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#include "maze_gen.h"
#include "maze_solv.h"

// UTILS
int current_column(int currrent_pos, int x);
int current_line(int current_pos, int y);

// FUNCTION GENERATOR

    // init_maze_struct.c
    char *init_maze(int x, int y);
    maze_t *init_maze_struct(int x, int y, int perf_imperf);

    //
    int dig_maze(maze_t *maze);
    stack_list_t *init_stack_list(void);
    void insert_move(stack_list_t *stack_list, int new_pos);
    void remove_move(stack_list_t *stack_list);
    int valid_moves(maze_t *maze);

    int check_right(maze_t *maze);
    int check_left(maze_t *maze);
    int check_down(maze_t *maze);
    int check_up(maze_t *maze);

// FUNCTION SOLVER

#endif /* !UTILS_DANTE_H_ */