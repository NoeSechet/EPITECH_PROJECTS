/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void print_nb_betw(int nb1, int nb2)
{
    while (nb1 <= nb2) {
        if (nb1 % 3 == 0 && nb1 % 5 == 0)
            printf("FizzBuzz\n");
        else if (nb1 % 3 == 0)
            printf("Fizz\n");
        else if (nb1 % 5 == 0)
            printf("Buzz\n");
        else
            printf("%d\n", nb1);
        nb1 += 1;
    }
}

int check_error(int ac, char **av)
{
    for (int i = 1; i < ac; i += 1) {
        for (int j = 0; av[i][j] != '\0'; j += 1)
            if (av[i][j] < 48 || av[i][j] > 57)
                return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 3) {
        return (84);
    }
    if (check_error(ac, av) == 1)
        return (84);
    if (atoi(av[2]) < atoi(av[1])) {
        write(2, "Error: the second parameter must be greater ", 44);
        write(2, "than the first one.\n", 20);
        return (84);
    }
    print_nb_betw(atoi(av[1]), atoi(av[2]));
    return (0);
}
