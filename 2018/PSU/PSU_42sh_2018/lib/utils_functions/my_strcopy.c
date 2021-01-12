/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_strcopy.c
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (!dest || !src)
        return (NULL);
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}