/*
** EPITECH PROJECT, 2018
** my_concat_params.c
** File description:
** put a string after another and make sure there is enough space for the added string
*/

#include <stdlib.h>
#include <libmy.a>

int my_putstr(char const *str);
int my_strlen(char const *str);

int my_count(int argc, char **argv)
{
    int nb = 0;

    for (int i = 0 ; i < argc ; i++) {
    	nb = nb + my_strlen(argv[i]) + 1;
    }
    return (nb);
}

char *concat_params(int argc, char **argv)
{
    int index = 0;
    int nbr = my_count(argc, argv);

    char *dest = malloc(sizeof(char) * nbr);
    	for (int i = 0 ; i < argc ; i++) {
		for (int j = 0 ; j < my_strlen(argv[i]) ; j++) {
    			dest[index] = argv[i][j];
    			index++;
   		}
   		dest[index] = '\n';
		index++;
	}
    dest[nbr - 1] = '\0';
    return (dest);
