/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** reallocarray
*/

#include "meta.h"
#include "errno.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t m_size = nmemb * size;

    if (nmemb > 0 && m_size / nmemb != size)
    {
        errno = ENOMEM;
        return NULL;
    }

    return realloc(ptr, nmemb * size);
}