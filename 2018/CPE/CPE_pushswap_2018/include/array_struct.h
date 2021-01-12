/*
** EPITECH PROJECT, 2018
** array_struct.h
** File description:
** array_struct
*/

#ifndef ARRAY_STRUCT_H
#define ARRAY_STRUCT_H

typedef struct array_s {
    int *list;
    int size;
    int min_value;
    int false_nbr;
} array_t;

#endif