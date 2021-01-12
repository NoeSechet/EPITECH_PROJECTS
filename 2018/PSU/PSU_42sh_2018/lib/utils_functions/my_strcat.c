/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_strcat.c
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *str_a, char *str_b)
{
    char *str = NULL;
    unsigned int x = 0;
    unsigned int y = 0;

    if (str_a == NULL || str_b == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (strlen(str_a) + strlen(str_b) + 1));
    for (x = 0; x < strlen(str_a); x++)
        str[x] = str_a[x];
    for (y = 0; y < strlen(str_b); y++) {
        str[x] = str_b[y];
        x++;
    }
    str[x] = '\0';
    return (str);
}