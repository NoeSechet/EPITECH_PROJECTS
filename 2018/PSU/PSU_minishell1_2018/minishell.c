/*
** EPITECH PROJECT, 2019
** minishell.c
** File description:
** minishell.c
*/

#include "include/utils.h"

static const minishell_t minilist[] = {
    {"cd", 2, &com_cd},
    {"setenv", 6, &com_setenv},
    {"unsetenv", 8, &com_unsetenv},
    {"env", 3, &com_env},
    {"./", 2, &com_exec},
    {"exit", 4, &com_exit},
    {0, 0, NULL}
};

int analyse_command(char **tab, list_t *list, char **environ)
{
    char *path = NULL;

    for (int i = 0; minilist[i].command != 0; i += 1)
        if (comp_word_pre(tab[0], minilist[i].command,
        minilist[i].length) == 1) {
            minilist[i].funcPointer(tab, list, environ);
            return (1);
        }
    if ((path = check_com_exist(tab, list, environ)) != NULL) {
        execute_binary(tab, environ, path);
    }
    return (0);
}

int launch_prog(list_t *list, char **environ)
{
    char *line = NULL;
    size_t size = 0;
    char cwd[4096];
    char **tab = NULL;

    while (1) {
        if (isatty(0) == 1)
            my_printf("%s: ", getcwd(cwd, 4096));
        if (getline(&line, &size, stdin) <= 0) {
            if (isatty(0) == 1)
                my_printf("exit\n");
            return (-1);
        }
        tab = my_str_to_word_array(line);
        analyse_command(tab, list, environ);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    (void)av;
    if (ac != 1)
        return (84);
    list_t *list = new_list();
    char **environ = env_copy(env);

    fill_env_list(list, environ);
    launch_prog(list, environ);
    return 0;
}