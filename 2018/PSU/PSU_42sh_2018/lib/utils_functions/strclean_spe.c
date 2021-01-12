/*
** EPITECH PROJECT, 2019
** clean
** File description:
** clean
*/

#include <stdlib.h>
#include <string.h>

int get_nb_c_begin(char *str, char c)
{
    int nb_c = 0;

    for (; str[nb_c] == c || str[nb_c] == '\t'; nb_c++);
    return (nb_c);
}

int get_nb_c_last(char *str, char c)
{
    int total = strlen(str);
    int nb_c = 0;

    for (; total != 0 && (str[total - 1] == c ||
    str[total - 1] == '\t'); total--)
        nb_c++;
    return (nb_c);
}

char *clean_all(char *str, char s)
{
    int size = 0;
    char *new_str = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != s)
            size += 1;
    }
    new_str = malloc(sizeof(char) * size + 1);
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != s) {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[size] = '\0';
    return (new_str);
}

char *strclean_spe(char *str, char c, int flag)
{
    int nb_c_begin = get_nb_c_begin(str, c);
    int nb_c_end = get_nb_c_last(str, c);
    int size_str = (strlen(str) - (nb_c_begin + nb_c_end)) + 1;
    char *new_str = malloc(sizeof(char) * size_str);
    int index = nb_c_begin;
    int i = 0;

    if (strlen(str) <= 1) {
        free(new_str);
        return (str);
    }
    if (flag == 1) {
        free(new_str);
        return (clean_all(str, c));
    }
    for (; (unsigned)index < strlen(str) - nb_c_end; index++, i++)
        new_str[i] = str[index];
    new_str[i] = '\0';
    return (new_str);
}