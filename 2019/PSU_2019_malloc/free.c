/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** free
*/

#include <unistd.h>
#include <stdio.h>

#include "meta.h"

int remove_elem(meta_t *temp)
{
    if (temp == metalist) {
        metalist = NULL;
    } else {
        for (; temp->prev != NULL && temp->prev->allocated == 0;
        temp = temp->prev);
        if (temp != metalist)
            temp->prev->next = NULL;
        else
            metalist = NULL;
    }
    brk(temp);
    temp = NULL;
    return 0;
}

void fusion_free(meta_t *temp)
{
    if (temp->next != NULL && temp->next->allocated == 0) {
        temp->elemsize += temp->next->elemsize;
        temp->next = temp->next->next;
    }
    if (temp->prev != NULL && temp->prev->allocated == 0) {
        temp->prev->elemsize += temp->elemsize;
        temp->prev->next = temp->next;
        temp = NULL;
    }
}

void free(void *ptr)
{
    meta_t *temp = metalist;
    if (ptr == NULL) {
        return;
    }
    for (; temp != NULL; temp = temp->next) {
        if (temp + sizeof(meta_t) == ptr && temp->next == NULL) {
            remove_elem(temp);
            return;
        } else if (temp + sizeof(meta_t) == ptr) {
            temp->allocated = 0;
            fusion_free(temp);
            return;
        }
    }
}