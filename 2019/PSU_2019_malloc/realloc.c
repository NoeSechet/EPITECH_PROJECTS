/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** realloc
*/

#include <unistd.h>
#include <string.h>

#include "meta.h"

void check_if_cut(meta_t *ite, char *addr, size_t nbPage)
{
    void *temp = NULL;

    if (ite->elemsize - nbPage * getpagesize() >=
    (size_t)(2 * getpagesize())) {
        temp = addr + ite->elemsize - nbPage * getpagesize();
        ((meta_t *)temp)->elemsize = nbPage * getpagesize();
        ((meta_t *)temp)->allocated = 0;
        ((meta_t *)temp)->prev = ite;
        ((meta_t *)temp)->next = ite->next;
        if (ite->next)
            ite->next->prev = (meta_t *)temp;
        ite->next = (meta_t *)temp;
        ite->elemsize = ite->elemsize - nbPage * getpagesize();
    }
}

bool check_self_space(char *addr, size_t size)
{
    size_t nbPage = get_nb_page(size);
    meta_t *ite = NULL;

    for (ite = metalist; ite->next != NULL; ite = ite->next)
        if ((ite + sizeof(meta_t)) == (meta_t *)addr)
            break;
    if (ite == NULL)
        return false;
    if (size < (ite->elemsize - sizeof(meta_t))) {
        check_if_cut(ite, addr, nbPage);
        return true;
    }
    return false;
}

void *realloc(void *ptr, size_t size)
{
    void *newAlloc = NULL;

    if (ptr == NULL && size == 0)
        return NULL;
    if (ptr == NULL)
        return malloc(size);

    if (check_self_space((char *)ptr, size) == true)
        return ptr;
    newAlloc = malloc(size);
    memcpy(newAlloc, ptr, size);
    if (newAlloc == NULL)
        return NULL;
    free(ptr);
    return newAlloc;
}