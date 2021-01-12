/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** my_isneg
*/

void my_putchar(char c);

int my_isneg(int i)
{
    if (i < 0)
    {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
