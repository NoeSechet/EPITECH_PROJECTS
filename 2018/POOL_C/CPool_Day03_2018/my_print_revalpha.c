/*  
//EPITECH PROJECT, 2018
//my_print_revalpha
//File description:
//alphabet backwards
*/  

void my_putchar(char c);

int my_print_revalpha(void)
{	 
    char alpha;

    alpha = 'z';
    while (alpha >= 'a')
    {
        my_putchar(alpha);
        alpha--;
    }
    return (0);
}
