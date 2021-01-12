/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** main.c
*/

#include "mysh.h"

void destroy_main_list(main_list_t *main_list)
{
    delete_list(main_list->env_loc);
    destroy_list(&main_list->env);
    destroy_list(&main_list->history);
    destroy_list(main_list->alias);
}

void init_main_list(main_list_t *main_list)
{
    main_list->str = NULL;
    init_list_haroun(&main_list->env);
    init_list_haroun(&main_list->history);
    main_list->alias = new_list();
    main_list->value_return = 0;
    main_list->env_loc = create_list(1);
    main_list->sec_path = NULL;
}

int main(int ac, char **av, char **env)
{
    (void)av;
    main_list_t main_list;
    int index = 0;

    if (ac == 1) {
        init_main_list(&main_list);
        stock_env(&main_list.env, env);
        if (main_list.env.start == NULL)
            create_new_env(&main_list.env);
        main_list.sec_path = get_path(&main_list.env);
        index = launch_shell(&main_list);
    }
    destroy_main_list(&main_list);
    return (index);
}
