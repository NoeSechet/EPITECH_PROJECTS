/*
** EPITECH PROJECT, 2018
** my_strcpxy.c
** File description:
** copy a string into another one
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
	dest[i] = src[i];
	i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
