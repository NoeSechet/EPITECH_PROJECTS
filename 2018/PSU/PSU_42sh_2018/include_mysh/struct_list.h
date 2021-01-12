/*
** EPITECH PROJECT, 2019
** struct_list.h
** File description:
** struct_list.h
*/

#ifndef STRUCT_LIST_H_
#define STRUCT_LIST_H_

#include "lib.h"

typedef struct main_list_s {
    list_t env;
    list_t history;
    list_t *alias;
    arraylist_t *env_loc;
    char *str;
    int value_return;
    char **sec_path;
} main_list_t;

typedef struct term_s
{
    struct termios old;
    struct termios new;
    char *str;
    char *prompt;
    int pos;
    int ver;
} term_t;

enum {
    n_flag,
    e_flag
};

#endif /* !STRUCT_LIST_H_ */
