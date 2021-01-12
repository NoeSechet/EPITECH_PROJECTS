/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** choose the bnumber of char you want to move to the dest from the src
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int d = 0;
    int s = 0;

    while (dest[d] != '\0') {
        d++;
    }
    while (src[s] && s < nb) {
        dest[d] = src[s];
	d++;
        s++;
    }
    return (dest);
}
