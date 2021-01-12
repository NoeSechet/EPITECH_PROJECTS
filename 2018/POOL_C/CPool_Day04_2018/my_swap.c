/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** switches 2 integers
*/

void my_swap(int *a, int *b)
{
    int blah;

    blah = *a;
    *a = *b;
    *b = blah;
}
