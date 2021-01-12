/*
** EPITECH PROJECT, 2018
** functionsIS.c
** File description:
** FunctionsIS
*/

#include "utils_printf.h"

void char_pointed(va_list args, int padder, int zero_padder)
{
    int nbr = va_arg(args, int);

    zero_padder_int(1, zero_padder);
    spaces_padder_int(1, padder);
    my_putchar(nbr);
}

void int_pointed(va_list args, int padder, int zero_padder)
{
    int nbr = va_arg(args, int);

    zero_padder_int(nbr, zero_padder);
    spaces_padder_int(nbr, padder);
    my_put_nbr(nbr);
}

void string_pointed(va_list args, int padder, int zero_padder)
{
    char *str = va_arg(args, char *);

    zero_padder_string(str, zero_padder);
    spaces_padder_string(str, padder);
    my_putstr(str);
}

void modulo_pointed(va_list args, int padder, int zero_padder)
{
    (void)zero_padder;
    (void)padder;
    (void)args;
    my_putchar('%');
}

void invis_string_pointed(va_list args, int padder, int zero_padder)
{
    char *str = va_arg(args, char *);

    zero_padder_string(str, zero_padder);
    spaces_padder_string(str, padder);
    show_invis_char(str);
}