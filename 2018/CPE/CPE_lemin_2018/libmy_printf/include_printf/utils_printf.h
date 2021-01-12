/*
** EPITECH PROJECT, 2019
** utils_printf.h
** File description:
** utils_printf.h
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

typedef unsigned int uint;

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strncmp(char const *s1, char const *s2, int n, int *index);
int show_invis_char(char *str);
int convert_nbr(char const *, int *);
void my_put_nbr(int nbr);
void my_put_nbr_base(int nbr, char *base);
void my_put_nbr_base_long(long nbr, char *base);
void my_put_nbr_base_long_long(long long nbr, char *base);
void my_put_nbr_base_u(uint, char *base);
void my_put_nbr_base_u_long(unsigned long nbr, char *base);
void my_put_nbr_base_u_long_long(unsigned long long nbr, char *base);
void spaces_padder_int(int nbr, int padder);
void spaces_padder_int_long(long int nbr, int padder);
void spaces_padder_int_long_long(long long int nbr, int padder);
void spaces_padder_int_u(uint nbr, int padder);
void spaces_padder_int_u_long(long unsigned nbr, int padder);
void spaces_padder_int_u_long_long(long long unsigned int nbr, int padder);
void spaces_padder_string(char *str, int padder);

void zero_padder_int(int nbr, int padder);
void zero_padder_int_long(long int nbr, int padder);
void zero_padder_int_long_long(long long int nbr, int padder);
void zero_padder_int_u(uint nbr, int padder);
void zero_padder_int_u_long(long unsigned nbr, int padder);
void zero_padder_int_u_long_long(long long unsigned int nbr, int padder);
void zero_padder_string(char *str, int padder);

void char_pointed(va_list args, int padder, int zero_padder);
void int_pointed(va_list args, int padder, int zero_padder);
void string_pointed(va_list args, int padder, int zero_padder);
void modulo_pointed(va_list args, int padder, int zero_padder);
void u_int_16_pointed(va_list args, int padder, int zero_padder);
void u_int_16_pointed_maj(va_list args, int padder, int zero_padder);
void u_int_8_pointed(va_list args, int padder, int zero_padder);
void u_int_2_pointed(va_list args, int padder, int zero_padder);
void pointer_pointed(va_list args, int padder, int zero_padder);
void invis_string_pointed(va_list args, int padder, int zero_padder);
void u_int_pointed(va_list args, int padder, int zero_padder);
void long_u_int_pointed(va_list args, int padder, int zero_padder);
void long_int_pointed(va_list args, int padder, int zero_padder);
void long_long_int_pointed(va_list args, int padder, int zero_padder);
void long_long_u_int_pointed(va_list args, int padder, int zero_padder);
void my_printf(char *s, ...);

#endif