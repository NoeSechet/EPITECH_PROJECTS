#include <unistd.h>

int my_print_comb(void);

void my_putchar(char c)
{
	write(1 ,&c, 1);
}

int main(void)
{
	return(my_print_cumb());
}
