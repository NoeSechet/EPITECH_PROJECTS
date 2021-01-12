/*
** EPITECH PROJECT, 2018
** functionsIS_2.c
** File description:
** functionsIS_2
*/

#include "utils.h"

void u_int_16_pointed(va_list args, int padder, int zero_padder)
{
    uint nbr = va_arg(args, uint);

    zero_padder_int_u(nbr, zero_padder);
    spaces_padder_int_u(nbr, padder);
    my_put_nbr_base_u(nbr, "0123456789abcdef");
}

void u_int_16_pointed_maj(va_list args, int padder, int zero_padder)
{
    uint nbr = va_arg(args, uint);

    zero_padder_int_u(nbr, zero_padder);
    spaces_padder_int_u(nbr, padder);
    my_put_nbr_base_u(nbr, "0123456789ABCDEF");
}

void u_int_8_pointed(va_list args, int padder, int zero_padder)
{
    uint nbr = va_arg(args, uint);

    zero_padder_int_u(nbr, zero_padder);
    spaces_padder_int_u(nbr, padder);
    my_put_nbr_base_u(nbr, "01234567");
}

void u_int_2_pointed(va_list args, int padder, int zero_padder)
{
    uint nbr = va_arg(args, uint);

    zero_padder_int_u(nbr, zero_padder);
    spaces_padder_int_u(nbr, padder);
    my_put_nbr_base_u(nbr, "01");
}

void pointer_pointed(va_list args, int padder, int zero_padder)
{
    long int nbr = va_arg(args, long int);

    zero_padder_int_long(nbr, zero_padder);
    spaces_padder_int_long(nbr, padder);
    my_putstr("0x");
    my_put_nbr_base_long(nbr, "0123456789abcdef");
}