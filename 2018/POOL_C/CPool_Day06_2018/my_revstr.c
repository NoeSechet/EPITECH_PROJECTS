/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** swap the letters in the string
*/

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0') {
	    len++;
    }
    return (len);
}

char *my_revstr(char *str)
{
    int d = 0;
    int l = my_strlen(str) - 1;
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
