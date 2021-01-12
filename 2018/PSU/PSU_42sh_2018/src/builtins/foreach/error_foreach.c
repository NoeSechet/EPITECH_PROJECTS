/*
** EPITECH PROJECT, 2019
** error foreach
** File description:
** error_foreach
*/

#include "mysh.h"

int check_var_name(char *var)
{
    if (!((*var >= 'a' && *var <= 'z') || (*var >= 'A' && *var <= 'Z'))) {
        write(1, "foreach: Variable name must begin with a letter.\n", 49);
        return (1);
    }
    for (int i = 1; var[i]; i++) {
        if (!((var[i] >= 'a' && var[i] <= 'z') || (var[i] >= 'A' &&
            var[i] <= 'Z') || (var[i] >= '0' && var[i] <= '9'))) {
            write(1, "foreach: Variable name", 22);
            write(1, " must contain alphanumeric characters.\n", 39);
            return (1);
        }
    }
    return (0);
}

int check_nbr_par(char **input)
{
    int right = 0;
    int left = 0;

    for (int i = 2; input[i]; i++) {
        for (int j = 0; input[i][j]; j++) {
            right = input[i][j] == ')' ? right + 1 : right;
            left = input[i][j] == '(' ? left + 1 : left;
        }
    }
    if (left < right)
        write(1, "Too many )\'s.\n", 15);
    if (left > right)
        write(1, "Too many (\'s.\n", 15);
    if (right == 0 && left == 0)
        write(1, "foreach: Words not parenthesized.\n", 34);
    if (left > right || left < right || left == 0)
        return (1);
    return (0);
}

int error_foreach(char **input)
{
    int len_tab = my_tablen(input);

    if (len_tab < 3) {
        my_printf("%s: Too few arguments.\n", input[0]);
        return (1);
    }
    if (check_var_name(input[1]))
        return (1);
    if (check_nbr_par(input))
        return (1);
    return (0);
}