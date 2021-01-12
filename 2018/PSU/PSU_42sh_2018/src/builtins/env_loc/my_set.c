/*
** EPITECH PROJECT, 2019
** local
** File description:
** local
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

void add_env_local(main_list_t *list, char *name, char *value)
{
    env_loc_t *elem = malloc(sizeof(env_loc_t));

    elem->var = strcopy_pos(name, 0);
    if (value == NULL)
        elem->val = NULL;
    else
        elem->val = strcopy_pos(value, 0);
    add_elem(list->env_loc, (void *)elem);
}

int is_exist(char *str, main_list_t *list)
{
    for (int i = 0;  i < list->env_loc->nb_elem; i++) {
        if (strcmp(str, ((env_loc_t *)list->env_loc->array[i])->var) == 0)
            return (true);
    }
    return (false);
}

void update_value_env_loc(char *str, char *value, main_list_t *list)
{
    for (int i = 0;  i < list->env_loc->nb_elem; i++) {
        if (strcmp(str, ((env_loc_t *)list->env_loc->array[i])->var) == 0) {
            if (value == NULL)
                ((env_loc_t *)list->env_loc->array[i])->val = NULL;
            else
                ((env_loc_t *)list->env_loc->array[i])->val
                = strcopy_pos(value, 0);
        }
    }
}

int my_set(main_list_t *list, tree_t *tree, char **input)
{
    (void)tree;
    int ret = 0;

    if (get_nb_str_array(input) == 1 && strcmp(input[0], "set") == 0)
        return (display_env_loc(list));
    for (int i = 1; input[i] != NULL; i++) {
        if ((ret = is_arg_spaced(input, list, &i)) == true)
            continue;
        if (ret == (-1) || set_var(input[i], list) == (-1)) {
            write(2, "set: Variable name must begin with a letter.\n", 45);
            sort_list_pieces(list->env_loc);
            return (1);
        }
        sort_list_pieces(list->env_loc);
    }
    return (0);
}
