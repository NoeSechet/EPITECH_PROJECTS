/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copy a string into another one
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    
    while (src[i] && i < n) {
	dest[i] = src[i];
	i++;
    }
    if (n > i) {
        dest[i] = '\0';
    }
    return (dest);
}
