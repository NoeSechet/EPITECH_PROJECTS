/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** jlehva
*/

int my_putstr(char const *str)
{		
    while (*str != '\0') {
	my_putchar(*str);
	str = str + 1;
	my_putchar('\n');
    }
    return (0); 
}
