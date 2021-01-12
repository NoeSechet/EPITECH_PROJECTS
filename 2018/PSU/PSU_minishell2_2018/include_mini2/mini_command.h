/*
** EPITECH PROJECT, 2019
** minishell.h
** File description:
** minishell.h
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "linked_list.h"
#include "bin_tree.h"

typedef struct minishell_s {
    char const *command;
    int length;
    int (*funcPointer)(char **, list_t *, bin_tree_t *);
} minishell_t;


// ---- MAIN COMMAND ---- //
int com_cd(char **tab, list_t *list, bin_tree_t *bin_tree);
int com_setenv(char **tab, list_t *list, bin_tree_t *bin_tree);
int com_unsetenv(char **tab, list_t *list, bin_tree_t *bin_tree);
int com_env(char **tab, list_t *list, bin_tree_t *bin_tree);
int com_exec(char **tab, list_t *list, bin_tree_t *bin_tree);
int com_exit(char **tab, list_t *list, bin_tree_t *bin_tree);


// ---- MAIN PROG ---- //
int analyse_command(bin_tree_t *bin_tree, list_t *list);
void check_status_error(int *sig);


char *check_com_exist(char **tab, list_t *list, bin_tree_t *bin_tree);
int execute_binary(char **tab, char *path, list_t *list, bin_tree_t *bin_tree);
int fork_exec(char *exec, char **tab, char **environ, bin_tree_t *bin_tree);
void status(int *i);

#endif /* !MINISHELL_H_ */