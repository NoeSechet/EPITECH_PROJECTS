/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** allocates memory instead of having a fixed array
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int j = 0;
    char *str;
    
    while (src[i] != '\0')
    	i++;

    str = malloc(sizeof(char) * (i + 1));

    while (j <= i) {
	    str[j] = src[j];
	    j++;
    }
    return (str);
}
