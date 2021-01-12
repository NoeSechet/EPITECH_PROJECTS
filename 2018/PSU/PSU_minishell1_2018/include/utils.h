/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include "minishell.h"
#include "linked_list.h"

void my_putchar(char c);
void my_printf(char *s, ...);
int my_strlen(char const *str);
char **env_copy(char **env);
void destroy_list(list_t *list);
void destroy_tab(char **tab);
int my_get_nbr(char const *str);

char **special_str_tab(char *str, char c);

int comp_word(char const *s1, char const *s2, int length);
char **my_str_to_word_array(char *prog);
char *get_environment_val(char *variable, list_t *list);

void update_newpwd(char *new_pwd, char *NEW_PWD, list_t *list);
void update_oldpwd(char *new_pwd, char *NEW_PWD, list_t *list);
char *fusion(char *dest, char *src);

int check_var(char const *s1, char const *s2, int length);
int comp_word_right(char const *s1, char const *s2, int length);
int comp_word_pre(char const *s1, char const *s2, int length);
int first_is_a_letter(char *);
int alphanum_char_only(char *);

void fill_env_list(list_t *list, char **env);
list_t *new_list(void);
list_t *insert_element_at(list_t *list, char *str, int index);
list_t *pop_element_at(list_t *list, int index);
void pop_front(list_t *list);

int com_cd(char **tab, list_t *list, char **environ);
int com_setenv(char **tab, list_t *list, char **environ);
int com_unsetenv(char **tab, list_t *list, char **environ);
int com_env(char **tab, list_t *list, char **environ);
int com_exec(char **tab, list_t *list, char **environ);
int com_exit(char **tab, list_t *list, char **environ);

char *check_com_exist(char **tab, list_t *list, char **environ);
int execute_binary(char **tab,
    char **environ, char *path);
int fork_exec(char *exec, char **tab, char **environ);
void status(int *i);

#endif /* !UTILS_H_ */