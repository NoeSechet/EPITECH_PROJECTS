/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** 
*/

char *my_strcat(char *dest, char const *src)
{
    int d = 0;
    int s = 0;

    while (dest[d] != '\0')
        d++;
    while (src[s]) {
        dest[d] = src[s];
        d++;
        s++;
    }
    return (dest);
}
