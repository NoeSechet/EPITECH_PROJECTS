/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct flag {
    char const *Type;
    int length;
    void (*funcPointer)(va_list, int, int);
} flag_t;

#endif