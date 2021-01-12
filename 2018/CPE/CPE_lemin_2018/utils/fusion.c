/*
** EPITECH PROJECT, 2019
** fusion.c
** File description:
** fusion.c
*/

#include "utils_lem_in.h"

char *fusion(char *dest, char *src)
{
    char *final_dest = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    while (dest[i += 1]);
    while (src[j += 1]);
    final_dest = malloc(sizeof(char) * (i + j + 1));
    for (; dest[k] != '\0'; k += 1)
        final_dest[k] = dest[k];
    for (int x = 0; src[x] != '\0'; x += 1) {
        final_dest[k] = src[x];
        k += 1;
    }
    final_dest[i + j] = '\0';
    return (final_dest);
}