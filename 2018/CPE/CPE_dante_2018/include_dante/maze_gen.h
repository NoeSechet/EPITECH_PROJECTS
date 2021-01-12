/*
** EPITECH PROJECT, 2019
** maze_gen.h
** File description:
** maze_gen.h
*/

#ifndef MAZE_GEN_H_
#define MAZE_GEN_H_

typedef struct move_s {
    int pos;
    struct move_s *next;
    struct move_s *previous;
} move_t;

typedef struct stack_list_s {
    int size;
    move_t *start;
    move_t *end;
} stack_list_t;

typedef struct maze_s {
    char *map;
    int width;
    int height;
    int current_pos;
    stack_list_t *stack_list;
} maze_t;

#endif /* !MAZE_GEN_H_ */