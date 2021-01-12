/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** pwd_manager.c
*/

#include "utils_mini2.h"

char *calc_pwd(char *start, char *NEW_PWD)
{
    char *str = malloc(sizeof(char) * (my_strlen(NEW_PWD) +
        my_strlen(start) + 1));
    int j = 0;

    for (int i = 0; start[i] != '\0'; i += 1, j += 1)
        str[i] = start[i];
    for (int i = 0; NEW_PWD[i] != '\0'; i += 1, j += 1)
        str[j] = NEW_PWD[i];
    str[my_strlen(NEW_PWD) + my_strlen(start)] = '\0';
    return (str);
}

void update_newpwd(char *new_pwd, char *NEW_PWD, list_t *list)
{
    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (comp_word(new_pwd, temp->str, my_strlen(new_pwd)) == 1) {
            free(temp->str);
            temp->str = calc_pwd("PWD=", NEW_PWD);
        }
}

void update_oldpwd(char *old_pwd, char *OLD_PWD, list_t *list)
{
    for (elem_t *temp = list->start; temp != NULL; temp = temp->next)
        if (comp_word(old_pwd, temp->str, my_strlen(old_pwd)) == 1) {
            free(temp->str);
            temp->str = calc_pwd("OLDPWD=", OLD_PWD);
        }
}