/*
** EPITECH PROJECT, 2018
** sum_stdarg.c
** File description:
** sum_stdarg
*/

#include <stdarg.h>

int sum_stdarg(int i, int nb, ...)
{
    int sum = 0;
    va_list args;

    if (i == 0) {
        va_start(args, nb);
        for (int j = 0; j < nb; j += 1)
            sum = sum + va_arg(args, int);
        va_end(args);
    }
    if (i == 1) {
        va_start(args, nb);
        for (int j = 0; j < nb; j += 1) {
            sum = sum + my_strlen(va_arg(args, char*));
        }
        va_end(args);
    }
    return (sum);
}