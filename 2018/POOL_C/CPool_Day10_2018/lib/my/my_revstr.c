/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** 
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int d = 0;
    int l = l = my_strlen(str) - 1;
    char buf;

    while (d < l) {
        buf = str[d];
        str[d] = str[l];
        str[l] = buf;
        d++;
        l--;
    }
    return (str);
}
