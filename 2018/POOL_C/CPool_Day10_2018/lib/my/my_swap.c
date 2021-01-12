/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** 
*/

void	my_swap(int *a, int *b)
{
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;
}
