/*
** EPITECH PROJECT, 2019
** local
** File description:
** local
*/

#ifndef local
#define local

typedef struct env_loc_s {
    char *var;
    char *val;
} env_loc_t;

int display_env_loc(main_list_t *list);
void update_value_env_loc(char *str, char *value ,main_list_t *list);
int is_exist(char *str, main_list_t *list);
void add_env_local(main_list_t *list, char *name, char *value);
int is_arg_spaced(char **input, main_list_t *list, int *i);
int set_var(char *arg, main_list_t *list);

#endif /* !local */
