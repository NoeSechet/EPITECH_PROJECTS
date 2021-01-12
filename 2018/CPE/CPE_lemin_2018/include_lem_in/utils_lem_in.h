/*
** EPITECH PROJECT, 2019
** utils_lemin.h
** File description:
** utils_lemin.h
*/

#ifndef UTILS_LEMIN_H_
#define UTILS_LEMIN_H_

typedef enum {
    false,
    true
} bool;

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "graph.h"
#include "pathing.h"

// - display_help.c
void display_help(void);

// - LIB
void my_printf(char *s, ...);
char *get_next_line(int fd);

// - utils
char *fusion(char *dest, char *src);
int my_getnbr(char const *str);
int str_n_comp(char const *s1, char const *s2, int length);
char *strcopy(char *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
char *int_to_char(int number);
char **str_to_word_array(char *str, char c);

void insert_new_path(ll_path_t *path, ll_box_t *list_box);
void delete_path(graph_t *graph, ll_box_t *list_box);

// - path_finding
vertex_t *get_exit(graph_t *graph);
vertex_t *get_start(graph_t *graph);


#endif /* !UTILS_LEMIN_H_ */