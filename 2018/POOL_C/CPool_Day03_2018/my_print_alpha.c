/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** ascending lowercase alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{	 
    char alpha;

    alpha = 'a';
    while (alpha <= 'z')
    {
        my_putchar(alpha);
        alpha = alpha + 1;
    }
    return (0);
}
