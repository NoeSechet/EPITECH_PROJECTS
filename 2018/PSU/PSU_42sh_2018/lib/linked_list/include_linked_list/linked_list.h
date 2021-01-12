/*
** EPITECH PROJECT, 2019
** linked_list.h
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct element_s {
    char *data;
    struct element_s *prev;
    struct element_s *next;
} elem_t;

typedef struct list_s {
    int size;
    elem_t *start;
    elem_t *end;
} list_t;

void insert_element_at(list_t *list, char *str, int index);
list_t *pop_element_at(list_t *list, int index);

elem_t *create_new_elem_haroun(char *);
void init_list_haroun(list_t *);
bool push_front_haroun(list_t *, char *);
bool push_back_haroun(list_t *, char *);
void pop_front_haroun(list_t *);
void pop_back_haroun(list_t *);
void print_elem_list(list_t *);
int strlen_for_list(list_t *list);
void pop_elem_haroun(list_t *, elem_t *);
bool push_elem_haroun(list_t *, char *, int);
void free_list(list_t *);
void destroy_list(list_t *list);

list_t *new_list(void);
void sort_list(list_t *list);
void push_end(list_t *list, elem_t *elem);
void push_start(list_t *list, elem_t *elem);
void pop_elem(list_t *list, elem_t *elem);
void pop_start(list_t *list);
void pop_end(list_t *list);

#endif /* !LINKED_LIST_H_ */
