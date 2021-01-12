/*
** EPITECH PROJECT, 2019
** solver
** File description:
** solver
*/

#ifndef MAZE_SOLV_H_
#define MAZE_SOLV_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct dijkstra_s {
    int width;
    int height;
    int total;
    int *PF;
    int COST;
} dijkstra_t;

int get_width(char * maze);
int get_height(char *maze);
char *strcopy(char *str);
char **special_str_tab(char *str, char c);
int my_strlen(char const *str);
char *get_maze(char *file_name);
void dijkstra(char *maze);
int current_column(int current_pos, int width);
int current_line(int current_pos, int width);
dijkstra_t *init_dijkstra(char *maze);
int *init_pf(int height, int width);
void update_path(dijkstra_t *dij, char *maze);
int current_line(int current_pos, int width);
int current_column(int current_pos, int width);

#endif /* !MAZE_SOLV_H_ */
