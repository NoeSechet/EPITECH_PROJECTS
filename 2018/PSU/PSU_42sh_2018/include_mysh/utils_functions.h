/*
** EPITECH PROJECT, 2019
** utils.h
** File description:
** utils.h
*/

#ifndef UTILS_H_
#define UTILS_H_

char *strcopy(char *str);
char *str_clean(char *str);
char *strclean_spe(char *str, char c, int flag);
void free_vars(char *a, char *b);
void free_tabs(char **);
int find_redirection(char *str);
int find_pipes(char *str);
int find_and_or_or(char *str);
char *my_strcat(char *str_a, char *str_b);
char **my_str_to_word_array(char *str, char sep1);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *a, char *b, int size);
char *my_strdup(char *str);
char **my_realloc_2d(char **tab_to, int size);
char *fusion(char *dest, char *src);
char **create_arg_tab(char *str, char c);
int count_pair(char **input, char memo);
int count_nb_arg(char *line, char c);
char **init_arg_tab(int nb_boxes);
int get_length(char *input, char c);
char count_nb_quotes(char *input);
char *init_tab(int len);
char **my_tabdup(char **old_tab);
char **my_tabcat(char **tab_a, char **tab_b);


#endif /* !UTILS_H_ */