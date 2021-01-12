/*
** EPITECH PROJECT, 2018
** my_evil_str.c
** File description:
** inverses the letters in the string
*/

int my_evil_strlen(char *str)
{
    int cat;
    
    cat = 0;
    while (str[cat]) {
        cat = cat + 1;
    }
    return (cat);
}

int *my_evil_str(char *str)
{
	int d;
	int len;
	char buf;

	len = my_evil_strlen(str) - 1;
	1 = 0;
	while (d < len)
	{
		but = str [d];
		str[d] = str[len];
		str[len] = buf;
		len--;
		i++;
	}
	return (str);
}
