/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** convert_list_env.c
*/

#include "utils_mini2.h"

char **convert_list_env(list_t *list)
{
    char **environ = malloc(sizeof(char *) * (list->length + 1));
    int i = 0;

    for (elem_t *temp = list->start; temp != NULL; temp = temp->next, i += 1) {
        environ[i] = temp->str;
    }

    environ[i] = '\0';
    return (environ);
}