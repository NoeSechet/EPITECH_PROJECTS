/*
** EPITECH PROJECT, 2019
** com_env.c
** File description:
** com_env.c
*/

#include "include/utils.h"

int com_env(char **tab, list_t *list, char **environ)
{
    (void)environ;
    (void)tab;
    for (elem_t *temp = list->start; temp != NULL; temp = temp->next) {
        my_printf("%s\n", temp->str);
    }
    return (0);
}