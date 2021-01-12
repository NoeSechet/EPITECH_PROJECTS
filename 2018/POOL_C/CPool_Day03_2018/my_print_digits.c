/*
** EPITECH PROJECT, 2018
** my_print_digits.c
** File description:
** going up digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    char digits;

    digits = '0';
    while (digits <= '9')
    {
	my_putchar(digits);
	digits++;
    }
    return (0);
}
