/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"

int *get_flags(char **args)
{
    int *flags = malloc(sizeof(int) * 2);

    flags[0] = 0;
    flags[1] = 0;
    for (int i = 1; i < 3; i++) {
        if (my_strcmp(args[i], "-n") == 0)
            flags[n_flag] = true;
        if (my_strcmp(args[i], "-e") == 0)
            flags[e_flag] = true;
    }
    return (flags);
}