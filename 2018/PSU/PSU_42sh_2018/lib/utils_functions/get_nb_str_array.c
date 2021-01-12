/*
** EPITECH PROJECT, 2019
** get
** File description:
** get
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"

int get_nb_str_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}