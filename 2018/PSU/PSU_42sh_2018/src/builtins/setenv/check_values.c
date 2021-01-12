/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** check_values
*/

#include "mysh.h"

int check_first(char *str)
{
    if (!(str[0] >= 'a' && str[0] <= 'z') &&
        !(str[0] >= 'A' && str[0] <= 'Z')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' &&
            str[i] <= 'Z') && !(str[i] >= '0' && str[i] <= '9')) {
            my_printf("setenv: Variable name must contain alphanumeric");
            my_printf(" characters.\n");
            return (1);
        } else
            continue;
    }
    return (0);
}
