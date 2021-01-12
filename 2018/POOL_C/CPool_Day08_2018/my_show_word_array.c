/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** displays the character strings 
*/

#include <unistd.h>
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    for (int a = 0 ; tab[a] != 0 ; a++) {
    	my_putstr(tab[a]);
    	my_putchar('\n');
    }
    return (0);
}
