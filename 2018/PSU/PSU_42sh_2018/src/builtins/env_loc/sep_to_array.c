/*
** EPITECH PROJECT, 2019
** sep
** File description:
** sep
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

int get_str1_size(char *str, char s)
{
    int i = 0;

    for (; str[i] != s && str[i] != '\0'; i++);
    return (i);
}

void set_array(char *str1, char *str2, char **array, int s_str2)
{
    array[0] = str1;
    if (s_str2 == 0) {
        array[1] = NULL;
        free(str2);
    } else {
        str2[s_str2 - 1] = '\0';
        array[1] = str2;
    }
    array[2] = NULL;
}

char **sep_to_array(char *str, char s)
{
    int s_str1 = get_str1_size(str, s);
    int s_str2 = strlen(str) - (s_str1);
    char **array = malloc(sizeof(char *) * 3);
    char *str1 = malloc(sizeof(char) * s_str1 + 1);
    char *str2 = malloc(sizeof(char) * s_str2 + 1);

    for (int i = 0; i < s_str1; i++) {
        str1[i] = str[i];
    }
    str1[s_str1] = '\0';
    for (int i = s_str1 + 1, j = 0;
    s_str2 != 0 && str[i] != '\0'; i++, j++) {
        str2[j] = str[i];
    }
    set_array(str1, str2, array, s_str2);
    return (array);
}