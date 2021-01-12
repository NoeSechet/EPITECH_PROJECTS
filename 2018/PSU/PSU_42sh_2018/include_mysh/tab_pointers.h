/*
** EPITECH PROJECT, 2019
** tab_pointers.h
** File description:
** tab_pointers.h
*/

#ifndef TAB_POINTERS_H_
#define TAB_POINTERS_H_

#include "struct_list.h"
#include "struct_tree.h"

typedef struct pointeur_s
{
    char *name;
    int (*pointeur)(main_list_t *, tree_t *, char **);
} pointeur_t;

typedef struct execution_s
{
    char *opperator;
    int (*func)(tree_t *, main_list_t *);
} execution_t;

#endif /* !TAB_POINTERS_H_ */
