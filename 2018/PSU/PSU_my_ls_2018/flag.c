/*
** EPITECH PROJECT, 2019
** flag.c
** File description:
** flag.c
*/

#include "utils.h"

flag_t *init_flag_struct(void)
{
    flag_t *flag = malloc(sizeof(flag_t));

    flag->d = 0;
    flag->r = 0;
    flag->d = 0;
    flag->t = 0;
    flag->R = 0;
    return (flag);
}

void check_flags(char *str, flag_t *flag)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        switch (str[i]) {
            case 'l': flag->l = 1;
                break;
            case 'r': flag->r = 1;
                break;
            case 'd': flag->d = 1;
                break;
            case 't': flag->t = 1;
                break;
            case 'R': flag->R = 1;
                break;
            default: break;
        }
    }
}

void fill_flag_struct(int ac, char **av, flag_t *flag, int *i)
{
    for (; *i < ac && av[*i][0] == '-'; *i += 1) {
        check_flags(av[1], flag);
    }
}