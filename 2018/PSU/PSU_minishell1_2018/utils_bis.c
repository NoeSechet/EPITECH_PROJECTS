/*
** EPITECH PROJECT, 2019
** utils_bis.c
** File description:
** utils_bis.c
*/

#include "include/utils.h"

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

char *fusion(char *dest, char *src)
{
    char *final_dest = NULL;
    int i = 0;
    int j = 0;
    int k = 0;

    while (dest[i += 1]);
    while (src[j += 1]);
    final_dest = malloc(sizeof(char) * (i + j + 1));
    for (; dest[k] != '\0'; k += 1)
        final_dest[k] = dest[k];
    for (int x = 0; src[x] != '\0'; x += 1) {
        final_dest[k] = src[x];
        k += 1;
    }
    final_dest[i + j] = '\0';
    return (final_dest);
}