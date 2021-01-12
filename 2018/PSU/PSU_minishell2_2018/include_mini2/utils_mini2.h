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
#include <signal.h>

#include "linked_list.h"

// -- utils.h
void my_putchar(char c);
void my_printf(char *s, ...);
int my_strlen(char const *str);
char **env_copy(char **env);
void destroy_list(list_t *list);
void destroy_tab(char **tab);
int my_get_nbr(char const *str);
int get_nb_words(char *line);
char **special_str_tab(char *str, char c);
char *strcopy(char *str);



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
void insert_element_at(list_t *list, char *str, int index);
list_t *pop_element_at(list_t *list, int index);
void pop_front(list_t *list);
char **convert_list_env(list_t *list);


#endif /* !UTILS_H_ */