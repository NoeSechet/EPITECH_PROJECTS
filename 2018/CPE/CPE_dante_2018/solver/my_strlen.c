/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
    a = a + 1;
    }
    return (a);
}