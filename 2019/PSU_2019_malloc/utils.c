/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** utils
*/

#include <unistd.h>

#include "meta.h"

meta_t *create_new_elem(size_t sizeElem)
{
    meta_t *newElem = sbrk(sizeof(char) * sizeElem);

    if (newElem == (void *)-1) {
        return NULL;
    }
    newElem->allocated = 1;
    newElem->elemsize = sizeElem;

    newElem->prev = NULL;
    newElem->next = NULL;

    return newElem;
}

size_t get_nb_page(size_t size)
{
    size_t nbPage = size / getpagesize() + 1;

    if (nbPage % 2 != 0) {
        nbPage += 1;
    }
    return nbPage;
}