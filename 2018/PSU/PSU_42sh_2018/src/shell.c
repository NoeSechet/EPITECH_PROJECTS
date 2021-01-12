/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** minishell2
*/

#include "mysh.h"

char *prompt_test;

char *display_prompt(list_t *env)
{
    char *prompt = my_strdup(get_from_env(env, "PWD"));
    char *cwd = my_strdup(prompt + 4);

    cwd = my_strcat(cwd, "/");
    prompt_test = my_strdup(cwd);
    return (cwd);
}

void sig_handler(int signum)
{
    if (signum == SIGINT) {
        write(1, "\n", 1);
        my_printf("%s $ ", prompt_test);
    }
}

int launch_shell(main_list_t *main_list)
{
    int i = 0;
    term_t term;

    while (1) {
        signal(SIGINT, sig_handler);
        signal(12, sig_handler);
        if (isatty(0)) {
            my_printf("%s $ ", display_prompt(&main_list->env));
            main_list->str = new_gnl(&term, display_prompt(&main_list->env),
            &main_list->history);
        } else
            main_list->str = get_next_line(0);
        stock_history(&main_list->history, main_list->str);
        if (main_list->str == NULL)
            return (i);
        i = execution(main_list);
        free(main_list->str);
    }
    return (i);
}
