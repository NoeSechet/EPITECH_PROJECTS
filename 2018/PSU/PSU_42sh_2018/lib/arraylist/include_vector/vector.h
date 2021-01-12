/*
** EPITECH PROJECT, 2019
** vector.h
** File description:
** vector.h
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct vector_s {
    int nb_elem;
    int size_alloc;
    void **array;
    int max_width;
    int max_height;
} arraylist_t;

arraylist_t *create_list(int size);
void delete_list(arraylist_t *list);
void resize_list_size(arraylist_t *list);
void add_elem(arraylist_t *list, void *elem);
void remove_elem_at(arraylist_t *list, int pos);
void *get_elem_at(arraylist_t *list, int pos);

#endif /* !VECTOR_H_ */