/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *dest, char *src);

char *my_strdup(char *str)
{
    char *new = NULL;

    if (str == NULL)
        return (NULL);
    new = malloc(sizeof(char) * strlen(str) + 1);
    if (new != NULL) {
        my_strcpy(new, str);
        return (new);
    } else
        return (NULL);
}