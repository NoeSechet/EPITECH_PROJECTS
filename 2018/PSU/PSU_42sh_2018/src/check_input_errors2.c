/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** chekc
*/

#include "mysh.h"

int find_opp(char *str)
{
    if (!str)
        return (1);
    if (strcmp(str, "|") == 0 || strcmp(str, "||") == 0 ||
    strcmp(str, ">") == 0 || strcmp(str, ">>") == 0 || strcmp(str, "<") == 0
    || strcmp(str, "<<") == 0 || strcmp(str, "&&") == 0|| strcmp(str, "(") == 0
    || strcmp(str, ")") == 0 || strcmp(str, ";") == 0)
        return (0);
    else
        return (1);
    return (0);
}

int next_op(char **pars, int i)
{
    while (pars[i] != NULL) {
        if (find_opp(pars[i]) == 0 && strcmp(pars[i], ";") == 0)
            return (0);
        if (find_opp(pars[i]) == 0 && strcmp(pars[i], ";") != 0)
            return (1);
        i++;
    }
    return (0);
}

int is__redirection(char *str)
{
    if (strcmp(str, ">") == 0 || strcmp(str, "<") == 0 ||
    strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0)
        return (0);
    return (1);
}
