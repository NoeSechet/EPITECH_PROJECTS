/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "include/utils.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

const flag_t list_flags[] = {
    {"c", 1, &char_pointed},
    {"i", 1, &int_pointed},
    {"d", 1, &int_pointed},
    {"u", 1, &u_int_pointed},
    {"li", 2, &long_int_pointed},
    {"ld", 2, &long_int_pointed},
    {"lu", 2, &long_u_int_pointed},
    {"lli", 3, &long_long_int_pointed},
    {"lld", 3, &long_long_int_pointed},
    {"llu", 3, &long_long_u_int_pointed},
    {"s", 1, &string_pointed},
    {"S", 1, &invis_string_pointed},
    {"%", 1, &modulo_pointed},
    {"x", 1, &u_int_16_pointed},
    {"X", 1, &u_int_16_pointed_maj},
    {"o", 1, &u_int_8_pointed},
    {"b", 1, &u_int_2_pointed},
    {"p", 1, &pointer_pointed},
    {0, 0, NULL}
};

int pad_zero(char *s, int *index)
{
    int zero_padder = 0;

    *index += 1;

    if (s[*index] == '0' || s[*index] == '.') {
        zero_padder = convert_nbr(s, index);
    } else {
        return (0);
    }
    return (zero_padder);
}

int paddle(char *s, int *index)
{
    int padder = 0;

    if (s[*index] <= '0' && s[*index] > '9')
        return (0);
    padder = convert_nbr(s, index);
    return (padder);
}

int check_flag(va_list args, char *s, int *index)
{
    int i = 0;
    int zero_padder = pad_zero(s, index);
    int padder = paddle(s, index);
    int compare = 0;

    while (list_flags[i].Type != 0) {
        compare = my_strncmp(list_flags[i].Type, s + *index,
        list_flags[i].length, index);
        if (compare == 1) {
            list_flags[i].funcPointer(args, padder, zero_padder);
            return (0);
        }
        i += 1;
    }
    return (0);
}

void my_printf(char *s, ...)
{
    va_list args;
    va_start(args, s);
    int index = 0;

    while (s[index] != '\0') {
        if (s[index] != '%')
            my_putchar(s[index]);
        if (s[index] == '%') {
            check_flag(args, s, &index);
            index -= 1;
        }
        index += 1;
    }
    va_end(args);
}