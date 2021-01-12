/*
** EPITECH PROJECT, 2019
** graph
** File description:
** graph
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include "utils_lem_in.h"

typedef enum  {
    not_available,
    available
} status_t;

typedef enum {
    start,
    end,
    lambda
} role_t;

/* ---------------------------- */

typedef struct node_s {
    char *ID_node;
    struct node_s *next;
    struct node_s *previous;
} node_t;

typedef struct ll_node_s {
    int size;
    node_t *start;
    node_t *end;
} ll_node_t;

typedef struct vertex_s {
    char *ID_vertex;
    role_t role;
    ll_node_t *list_node;
    struct vertex_s *next;
} vertex_t;

typedef struct graph_s {
    int nb_ants;
    int nb_vertices;
    vertex_t *list_vertex;
} graph_t;

// - function_graph
graph_t *create_graph(void);
graph_t *init_graph(void);

    // - complete_graph
    int complete_graph(graph_t *graph, char **script_tab);
    int complete_vertex(graph_t *graph, char **script_tab, int *i);
    int complete_node(graph_t *graph, char **script_tab, int *i);

node_t *create_node(char *str);
void add_vertex(graph_t *graph, char *str, role_t role);
void print_graph(graph_t *graph);
int add_edge(graph_t *graph, char *node_1, char *node_2);
void free_graph(graph_t *graph);

#endif /* !GRAPH_H_ */