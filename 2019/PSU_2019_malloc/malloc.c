/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** malloc
*/

#include <unistd.h>
#include <stdio.h>

#include "meta.h"

meta_t *metalist = NULL;

int is_first_init(size_t nbPage)
{
    meta_t *newElem = NULL;

    if (metalist != NULL) {
        return 2;
    }
    if ((newElem = create_new_elem(nbPage * getpagesize())) == NULL)
        return 0;
    metalist = newElem;

    return 1;
}

void check_needed_space(meta_t *temp, char *addr, size_t nbPage)
{
    void *cutTemp = NULL;

    if (temp->elemsize / getpagesize() - nbPage >= 2) {

        cutTemp = addr + nbPage * getpagesize();

        ((meta_t *)cutTemp)->allocated = 0;
        ((meta_t *)cutTemp)->prev = temp;
        ((meta_t *)cutTemp)->next = temp->next;
        if (temp->next->prev)
            temp->next->prev = (meta_t *)cutTemp;
        temp->next = (meta_t *)cutTemp;
    }
}

// here I look for potential free space in the memory I already allocated
void *get_free_space(size_t nbPage)
{
    meta_t *temp = metalist;
    meta_t *newElem = NULL;

    for (; temp != NULL; temp = temp->next) {
        // if valid mem space then we return than space
        if (temp->allocated == 0 && temp->elemsize > nbPage * getpagesize()) {
            check_needed_space(temp, (char *)temp, nbPage);
            temp->allocated = 1;
            return temp;
        }
        if (temp->next == NULL)
            break;
    }
    // we create a new elem at the end of our list
    if ((newElem = create_new_elem(nbPage * getpagesize())) == NULL)
        return NULL;

    temp->next = newElem;
    newElem->prev = temp;

    return newElem;
}

void *malloc(size_t size)
{
    size_t nbPage = get_nb_page(size);
    int first_init = 0;

    first_init = is_first_init(nbPage);

    if (first_init == 0) {
        return NULL;
    } else if (first_init == 1) {
        return metalist + sizeof(meta_t);
    }
    void *temp = get_free_space(nbPage);
    if (temp == NULL) {
        return NULL;
    }
    return temp + sizeof(meta_t);
}