/*
** EPITECH PROJECT, 2019
** useful function
** File description:
** useful_function
*/

#include "lib.h"

int strlenght(char const *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

char *copycat(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (strlenght(s1) + strlenght(s2) + 1));

    for (; i < n; i++)
        dest[i] = s1[i];
    for (; s2[j]; j++)
        dest[i + j] = s2[j];
    dest[i + j] = '\0';
    return (dest);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] - s2[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while ((s1[i] || s2[i]) && i < n) {
        if (s1[i] - s2[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

int getnbr(char *str, int i)
{
    int nbr = 0;
    int neg = 0;

    while ((str[i] == '-' || str[i] == '+') && (str[i])) {
        if (str[i] == '-')
            neg++;
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10;
        nbr = nbr + (str[i] - '0');
        i += 1;
    }
    if ((neg % 2) == 1)
        nbr = - nbr;
    if ((nbr < 0 && neg % 2 == 0) || (nbr > 0 && neg % 2 == 1))
        return (0);
    return (nbr);
}