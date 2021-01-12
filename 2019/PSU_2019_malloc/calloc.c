/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** calloc
*/

#include <unistd.h>
#include "meta.h"

void *calloc(size_t nmemb, size_t size)
{
    void *data = NULL;
    char *bytes_ver = NULL;

    if ((data = malloc(nmemb * size)) == NULL) {
        return NULL;
    }
    bytes_ver = data;
    for (size_t i = 0; i < nmemb * size; i += 1) {
        bytes_ver[i] = 0;
    }
    return data;
}