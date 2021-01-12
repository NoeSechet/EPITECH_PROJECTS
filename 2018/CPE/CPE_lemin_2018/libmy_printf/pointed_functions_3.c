/*
** EPITECH PROJECT, 2018
** pointed_functions_3.c
** File description:
** pointed_functions_3
*/

#include "utils_printf.h"

void u_int_pointed(va_list args, int padder, int zero_padder)
{
    uint nbr = va_arg(args, uint);

    zero_padder_int_u(nbr, zero_padder);
    spaces_padder_int_u(nbr, padder);
    my_put_nbr_base_u(nbr, "0123456789");
}

void long_u_int_pointed(va_list args, int padder, int zero_padder)
{
    long unsigned int nbr = va_arg(args, long unsigned int);

    zero_padder_int_u_long(nbr, zero_padder);
    spaces_padder_int_u_long(nbr, padder);
    my_put_nbr_base_u_long(nbr, "0123456789");
}

void long_long_u_int_pointed(va_list args, int padder, int zero_padder)
{
    long long unsigned int nbr = va_arg(args, long long unsigned int);

    zero_padder_int_u_long_long(nbr, zero_padder);
    spaces_padder_int_u_long_long(nbr, padder);
    my_put_nbr_base_u_long_long(nbr, "0123456789");
}

void long_int_pointed(va_list args, int padder, int zero_padder)
{
    long int nbr = va_arg(args, long int);

    zero_padder_int_long(nbr, zero_padder);
    spaces_padder_int_long(nbr, padder);
    my_put_nbr_base_long(nbr, "0123456789");
}

void long_long_int_pointed(va_list args, int padder, int zero_padder)
{
    long long int nbr = va_arg(args, long long int);

    zero_padder_int_long_long(nbr, zero_padder);
    spaces_padder_int_long_long(nbr, padder);
    my_put_nbr_base_long_long(nbr, "0123456789");
}