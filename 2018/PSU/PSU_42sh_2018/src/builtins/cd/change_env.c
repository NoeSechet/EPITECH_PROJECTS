/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** change env
*/

#include "mysh.h"

void change_old_pwd(list_t *list, char *old)
{
    elem_t *elem = list->start;

    for (; elem != NULL && elem->data != NULL; elem = elem->next)
        if (my_strncmp(elem->data, "OLDPWD=", 7) == 0 || !elem || !elem->data)
            break;
    if (!elem || !elem->data) {
        push_back_haroun(list, my_strcat("OLDPWD=", old + 4));
        return;
    }
    elem->data = my_strcat("OLDPWD=", old + 4);
}

void change_env(list_t *list)
{
    elem_t *elem = list->start;
    char *old_pwd = get_from_env(list, "PWD=");
    char pwd[4096];

    getcwd(pwd, 4096);
    change_old_pwd(list, old_pwd);
    for (; elem != NULL; elem = elem->next)
        if (my_strncmp(elem->data, "PWD=", 4) == 0)
            break;
    if (!elem || !elem->data)
        return;
    elem->data = my_strcat("PWD=", pwd);
}
