/*
** EPITECH PROJECT, 2019
** minishell.h
** File description:
** minishell.h
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "linked_list.h"

typedef struct minishell_s {
    char const *command;
    int length;
    int (*funcPointer)(char **, list_t *, char **);
} minishell_t;

#endif /* !MINISHELL_H_ */