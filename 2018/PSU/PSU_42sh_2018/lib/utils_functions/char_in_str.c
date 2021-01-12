/*
** EPITECH PROJECT, 2019
** char
** File description:
** char
*/

int char_in_str(char *str, char c)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            nb += 1;
    }
    return (nb);
}