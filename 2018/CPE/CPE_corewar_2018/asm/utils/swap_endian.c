/*
** EPITECH PROJECT, 2019
** swap
** File description:
** swap
*/

#include "utils.h"
#include "lib.h"

void swap_endian(void *obj, size_t size)
{
    char *buf = (char *)obj;
    char c;

    for (size_t i = 0; i < size / 2; i++) {
        c = buf[size - i - 1];
        buf[size - i - 1] = buf[i];
        buf[i] = c;
    }
}