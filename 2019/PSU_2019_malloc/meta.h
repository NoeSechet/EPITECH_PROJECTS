/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** meta
*/

#ifndef META_H_
#define META_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct meta_s {
    bool allocated;
    size_t elemsize;

    struct meta_s *prev;
    struct meta_s *next;
} meta_t;

extern meta_t *metalist;

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);

meta_t *create_new_elem(size_t sizeElem);
size_t get_nb_page(size_t size);

#endif /* !META_H_ */