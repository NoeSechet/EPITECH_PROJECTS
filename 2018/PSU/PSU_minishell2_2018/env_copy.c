/*
** EPITECH PROJECT, 2019
** env_copy.c
** File description:
** env_copy.c
*/

#include "utils_mini2.h"

char *copy_env_into_new_env(char *env)
{
    char *str = malloc(sizeof(char) * (my_strlen(env) + 1));

    for (int i = 0; env[i] != '\0'; i += 1) {
        str[i] = env[i];
    }
    str[my_strlen(env)] = '\0';
    return (str);
}

char **env_copy(char **env)
{
    char **new_env = NULL;
    int i = 0;

    for (; env[i] != NULL; i += 1);
    new_env = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; env[j] != NULL; j += 1) {
        new_env[j] = copy_env_into_new_env(env[j]);
    }
    new_env[i] = NULL;
    return (new_env);
}