/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my_strcmp.c
*/

int my_strncmp(char *a, char *b, int size)
{
    if (!a || !b)
        return (1);
    for (int i = 0, j = 0; i != size && j != size; i++, j++) {
        if (a[i] != b[j])
            return (1);
        if ((i == size && j != size) || (i != size && j == size))
            return (1);
    }
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (1);
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}