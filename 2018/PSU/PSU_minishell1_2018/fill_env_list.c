/*
** EPITECH PROJECT, 2019
** fill_env_list.c
** File description:
** fill_env_list.c
*/

#include "include/utils.h"

void fill_env_list(list_t *list, char **environ)
{
    for (int i = 0; environ[i] != NULL; i += 1) {
        insert_element_at(list, environ[i], list->length);
    }
}