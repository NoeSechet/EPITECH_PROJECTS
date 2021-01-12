/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils.c
*/

#include "utils_mini2.h"

char *get_environment_val(char *variable, list_t *list)
{
    char *value = NULL;

    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (comp_word(variable, temp->str, my_strlen(variable)) == 1) {
            value = temp->str + my_strlen(variable) + 1;
            return (value);
        }
    return (NULL);
}