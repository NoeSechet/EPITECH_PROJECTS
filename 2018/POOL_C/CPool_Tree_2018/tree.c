/*
** EPITECH PROJECT, 2018
** tree.c
** File description:
** building a fucking tree
*/

#include <unistd.h>

void my_putchar(char c);

int trunk(int size)
{
    int w = 0;
    int d = size;
    int l = 0;
    
    if (size % 2 == 0) {
    	d = d + 1;
    }
    while (w <= size) {
       	w++;
    	while (l <= d) {
		my_putchar('|');
		l++;
	}
    	my_putchar('\n');
    	l = 0;
    }
    return (0);
}
