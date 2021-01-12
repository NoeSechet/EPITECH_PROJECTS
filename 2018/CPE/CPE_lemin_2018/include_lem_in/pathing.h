/*
** EPITECH PROJECT, 2019
** pathing.h
** File description:
** pathing.h
*/

#ifndef PATHING_H_
#define PATHING_H_

#include "utils_lem_in.h"

typedef struct box_s {
    int ID_ant;
    char *ID_box;
    role_t role;
    status_t status;
    struct box_s *previous;
    struct box_s *next;
} box_t;

typedef struct ll_box_s {
    int size;
    box_t *start;
    box_t *end;
} ll_box_t;

typedef struct path_s {
    ll_box_t *list_box;
    struct path_s *next;
    struct path_s *previous;
} path_t;

typedef struct ll_path_s {
    int nb_path;
    path_t *start;
    path_t *end;
} ll_path_t;

vertex_t *get_start(graph_t *graph);
vertex_t *get_exit(graph_t *graph);
vertex_t *get_vertex(graph_t *graph, char *ID_vertex);

ll_path_t *create_list_path(graph_t *graph);
ll_box_t *init_list_box(void);
int fill_list_path(graph_t *graph, ll_path_t *list_path);

void insert_node_in_new_path(char *ID_node, ll_box_t *list_box);
path_t *init_path(void);
ll_path_t *init_list_path(void);


#endif /* !PATHING_H_ */