/*
** EPITECH PROJECT, 2019
** utils_tetris.h
** File description:
** utils_tetris.h
*/

#ifndef UTILS_TETRIS_H_
#define UTILS_TETRIS_H_

#include "lib.h"
#include "struct_list.h"
#include "struct_tree.h"
#include "tab_pointers.h"

// --- KEYS --- //

#define K_UP 0x415B
#define K_DWN 0x425B
#define K_RGT 0x435B
#define K_LFT 0x445B

// -- UTILS --- //
int my_tablen(char **);
char *strclean_spe(char *str, char c, int flag);
int char_in_str(char *str, char c);
int get_nb_str_array(char **array);
char *strcopy_pos(char *str, int begin);
void sort_list_pieces(arraylist_t *list);
char **sep_to_array(char *str, char s);

// -- MAIN -- //
int launch_shell(main_list_t *main_list);
void stock_env(list_t *list, char **env);


// --- EXECUTION --- //
int exec_double_redirection_left(tree_t *tree, main_list_t *);
int exec_double_redirection_right(tree_t *tree, main_list_t *);
int exec_semi_colomn(tree_t *tree, main_list_t *);
int exec_left_redirection(tree_t *tree, main_list_t *);
int exec_right_redirection(tree_t *tree, main_list_t *);
int do_execution(tree_t *tree, main_list_t *);
int exec_pipe(tree_t *tree, main_list_t *);
int exec_or(tree_t *tree, main_list_t *);
int exec_and(tree_t *tree, main_list_t *);
int exec_with_path(char **command, char **env, tree_t *tree, char **path);

char **check_var_inter(main_list_t *main_list, char **tab_check);
int my_fork(char **comand, tree_t *tree, char **env);
int my_exec(main_list_t *, char **command, tree_t *tree);
int my_exec_alias(main_list_t *main, char **command, tree_t *tree);
int execution(main_list_t *main);
int check_signal(int status);
int type_exec(main_list_t *main, tree_t *tree);
void check_dup(tree_t *tree, int *fptr);


// --- BUILT IN --- //
int find_builtin(main_list_t *, char **inp, tree_t *tree);
int my_exit(main_list_t *, tree_t *,char **);
int my_unsetenv(main_list_t *, tree_t *, char **);
int my_setenv(main_list_t *, tree_t *, char **);
int my_env(main_list_t *, tree_t *, char **);
int my_cd(main_list_t *, tree_t *, char **);
int my_alias(main_list_t *, tree_t *, char **);
int my_which(main_list_t *, tree_t *, char **);
int my_foreach(main_list_t *, tree_t *, char **);
int my_unalias(main_list_t *, tree_t *, char **);
int my_repeat(main_list_t *, tree_t *, char **);
int my_history(main_list_t *, tree_t *, char **);
int my_echo(main_list_t *, tree_t *, char **);
int my_set(main_list_t *, tree_t *, char **);
int my_unset(main_list_t *, tree_t *, char **);
int my_if(main_list_t *, tree_t *, char **);
int my_where(main_list_t *, tree_t *, char **);

int check_alias_where(list_t *alias, char *cmd);
int check_type_command(char *command);
int check_alias_where(list_t *alias, char *cmd);
int check_alias_which(list_t *alias, char *cmd);
int check_builtin(char **tab_built, char *cmd);
int check_type_command_which(char *command);
int check_which_builtin(char **tab_built, char *cmd);
void stock_history(list_t *history, char *str);
void change_env(list_t *list);
int error_repeat(char **input);
int gest_error(char *buf, int ret);
void change_value(char *elem, char *value, list_t *list, int size);
int do_setenv_2(list_t *list, char *name, char *value);
char *concat_elem(char *elem, char *value);
int check_first(char *str);
int check_if_folder(char *input);
int echo_error(char **args, int *flags, main_list_t *list);
int is_flag(char *str);
int *get_flags(char **args);
int echo_dollars(char *str, main_list_t *list, int n);
int is_var_env_loc(char *cmd, main_list_t *list);
int is_var_env(char *command, main_list_t *list);
void remove_if_aliased(list_t *alias, char *input);
char *remove_quotes_alias(char *str);

char **get_globbings(char *arg);
char **remove_hiden_globbings(char **input);
char **my_globbings(char **input);


// --- GET FUNCTIONS --- //
char **get_path(list_t *list);
char **get_new_env(list_t *list);
char *get_from_env(list_t *list, char *info);
char **check_alias(char **cmd, list_t *alias);
int check_alias_loop(list_t *alias, char *input, char *first_input);


// --- CREATE FUNCTIONS --- //
void create_new_env(list_t *list);

// --- HISTORY --- ARROWS //
char *new_gnl(term_t *all, char *s, list_t *);
char *add_changes(char *dest, char *src, int pos);
void arrow_control(term_t *all, list_t *history, int *);
void add_character_str(char c, term_t *all);
void remove_character(term_t *all);

// --- errors //

int is__redirection(char *str);
int next_op(char **pars, int i);
int find_opp(char *str);
int valid_str(char *str);

#endif /* !UTILS_TETRIS_H_ */
