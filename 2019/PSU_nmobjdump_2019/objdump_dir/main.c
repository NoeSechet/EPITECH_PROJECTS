/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "objd.h"

unsigned char check_flag_av(char *str, Flag_e *flag)
{
    size_t counter = 0;

    for (int i = 1; str[i]; i += 1) {
        if (str[i] == 'f') {
            *flag = F_FLAG;
            counter += 1;
        }
        else if (str[i] == 's') {
            *flag = S_FLAG;
            counter += 1;
        } else {
            return str[i];
        }
    }
    if (counter >= 2)
        *flag = F_S_FLAG;
    return 's';
}

int get_flag(size_t ac, char **av, unsigned char *error, Flag_e *flag)
{
    int counter = 0;

    for (size_t i = 0; i < ac; i += 1) {
        if (av[i][0] == '-') {
            *error = check_flag_av(av[i], flag);
            if (*error != 's')
                return 0;
            counter += 1;
        }
    }
    return counter;
}

int main(int ac, char **av)
{
    int res = 0;
    Flag_e flag = 0;
    unsigned char error = 0;
    size_t flag_counter = 0;

    if (ac == 1)
        return print_usage();
    if ((flag_counter = get_flag(ac, av, &error, &flag)) == 0)
        return print_flag_error(error);

    switch (flag) {
        case F_FLAG: res = launch_f_objd(ac, ac - flag_counter - 1, av);
            break;
        case S_FLAG: res = launch_s_objd(ac, ac - flag_counter - 1, av);
            break;
        case F_S_FLAG: res = launch_f_s_objd(ac, ac - flag_counter - 1, av);
            break;
        default: return 1; break;
    }
    return res;
}