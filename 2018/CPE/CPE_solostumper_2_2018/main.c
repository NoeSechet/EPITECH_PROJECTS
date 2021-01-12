/*
** EPITECH PROJECT, 2019
** solo_stumper_2.c
** File description:
** solo_stumper_2.c
*/

#include "utils.h"

int my_strlen_skip_spaces(char *str)
{
    int i = 0;
    int len = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' && (str[i+1] == ' ' ||
            str[i+1] == '\t'))
            i += 1;
        i += 1;
        len += 1;
    }
    return (len);
}

char *rostring(char *str)
{
    int i = 0;
    int x = 0;
    char *temp = malloc(sizeof(char) * (my_strlen_skip_spaces(str) + 1));
    char *first_word = NULL;

    while (str[i += 1] != ' ' && str[i += 1] != '\t');
    first_word = malloc(sizeof(char) * (i + 2));
    first_word[0] = ' ';
    for (int k = 0; str[k] != ' ' && str[k] != '\t'; k += 1)
        first_word[k + 1] = str[k];
    i += 1;
    for (; str[i] != '\0'; x += 1, i += 1) {
        while (str[i] == ' ' && str[i+1] == ' ')
            i += 1;
        temp[x] = str[i];
    }
    for (int k = 0; first_word[k] != '\0'; k += 1, x += 1)
        temp[x] = first_word[k];
    free(first_word);
    return (temp);
}

int main(int ac, char **av)
{
    char *str = NULL;

    if (ac == 1) {
        my_putchar('\n');
        return (0);
    }
    if (ac != 2)
        return (84);
    str = rostring(av[1]);
    my_putstr(str);
    my_putchar('\n');
    return (0);
}
