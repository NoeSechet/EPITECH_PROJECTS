/*
** EPITECH PROJECT, 2019
** cat
** File description:
** cat
*/

#include "utils.h"

char *cat(char *str_1, char *str_2)
{
    char *temp = NULL;
    int size_1 = 0;
    int size_2 = 0;
    int i = 0;
    int j = 0;

    for (; str_1[size_1] != '\0'; size_1 += 1);
    for (; str_2[size_2] != '\0'; size_2 += 1);
    temp = malloc(sizeof(char) * (size_1 + size_2 + 1));
    for (; i < size_1; i++)
        temp[i] = str_1[i];
    for (; j < size_2; j++)
        temp[j + i] = str_2[j];
    temp[j + i] = '\0';
    return (temp);
}