/*
** EPITECH PROJECT, 2019
** strclean
** File description:
** strclean
*/

#include <stdlib.h>
#include <string.h>

char *str_clean(char *st)
{
    char *new_str = NULL;
    int j = 0;

    if (!st)
        return (NULL);
    new_str = malloc(sizeof(char) * (strlen(st) + 1));
    for (int i = 0; st[i] != '\0'; i++) {
        if ((st[i] != ' ' && st[i] != '\0') || ((st[i] == ' ' || st[i] == '\t')
            && st[i + 1] != ' ' && st[i + 1] != '\t' && st[i + 1] != '\0')) {
            new_str[j] = st[i];
            j++;
        }
    }
    new_str[j] = '\0';
    (new_str[0] == ' ') ? new_str = new_str + 1 : 0;
    return (new_str);
}
