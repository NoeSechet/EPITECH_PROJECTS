/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_input_errors
*/

#include "mysh.h"

int check_first_param(char *new_str)
{
    if (strcmp(new_str, "|") == 0 || strcmp(new_str, "| ") == 0) {
        my_printf("Invalid null command.\n");
        return (1);
    } else if (is__redirection(new_str) == 0) {
        my_printf("Missing name for redirect.\n");
        return (1);
    }
    return (0);
}

int check_ambiguious(char **pars)
{
    for (int i = 0; pars[i] != NULL; i++) {
        if (find_opp(pars[i]) == 0 && (strcmp(pars[i], ">") == 0 ||
        strcmp(pars[i], "<") == 0 || strcmp(pars[i], "<<") == 0 ||
        strcmp(pars[i], ">>") == 0) && next_op(pars, i + 1) != 0) {
            my_printf("Ambiguous output redirect.\n");
            return (1);
        }
    }
    return (0);
}

int valid_str(char *str)
{
    char *new_str = str_clean(str);
    char **pars = NULL;

    if (check_first_param(new_str) != 0)
        return (1);
    pars = my_str_to_word_array(new_str, ' ');
    return (check_ambiguious(pars));
}
