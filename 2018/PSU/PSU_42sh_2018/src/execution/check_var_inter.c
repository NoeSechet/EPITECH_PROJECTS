/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** check_var_inter.c
*/

#include "mysh.h"
#include "env_loc.h"

void clean_var_inter(char **copy)
{
    for (; *copy[0] != '\0' && *copy[0] != '='; *copy += 1);
    if (*copy[0] != '\0')
        *copy += 1;
}

char *get_from_env_shell(char *str, main_list_t *list)
{
    for (int i = 0;  i < list->env_loc->nb_elem; i++)
        if (strcmp(str, ((env_loc_t *)list->env_loc->array[i])->var) == 0)
            return (((env_loc_t *)list->env_loc->array[i])->val);
    return (NULL);
}

char *brows_envs(char *str, main_list_t *main_list)
{
    char *copy = NULL;

    if ((copy = get_from_env(&main_list->env, str + 1)) != NULL) {
        clean_var_inter(&copy);
        return (copy);
    }
    if ((copy = get_from_env_shell(str + 1, main_list)) != NULL) {
        return (copy);
    }
    return (str);
}

char **check_var_inter(main_list_t *main_list, char **tab_check)
{
    if (tab_check == NULL)
        return (tab_check);
    for (int i = 0; tab_check[i] != NULL; i += 1)
        if (tab_check && tab_check[i][0] == '$') {
            tab_check[i] = brows_envs(tab_check[i], main_list);
        }
    return (tab_check);
}