/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** error repeat
*/

#include "mysh.h"

int check_the_param(char *param)
{
    for (int i = 0; param[i] != '\0'; i++)
        if (!(param[i] >= '0' && param[i] <= '9'))
            return (1);
    return (0);
}

int error_repeat(char **input)
{
    if (my_tablen(input) < 3) {
        my_printf("%s: Too few arguments.\n", input[0]);
        return (1);
    }
    if (my_tablen(input) >= 3 && check_the_param(input[1]) == 1) {
        my_printf("%s: Badly formed number.\n", input[0]);
        return (1);
    }
    return (0);
}
