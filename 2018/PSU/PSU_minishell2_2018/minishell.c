/*
** EPITECH PROJECT, 2019
** minishell.c
** File description:
** minishell.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

int launch_prog(list_t *list, size_t size)
{
    char *input = NULL;
    char cwd[4096];
    bin_tree_t *bin_tree = NULL;
    char *input_copy = NULL;

    while (1) {
        if (isatty(0) == 1)
            my_printf("%s: ", getcwd(cwd, 4096));
        if (getline(&input, &size, stdin) <= 0) {
            if (isatty(0) == 1)
                my_printf("exit\n");
            return (-1);
        }
        input[my_strlen(input) - 1] = '\0';
        input_copy = strcopy(input);
        bin_tree = create_new_node(input_copy);
        complete_bin_tree(bin_tree, bin_tree->command_parser);
        execute_bin_tree(bin_tree, list);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    (void)av;
    size_t size = 0;
    if (ac != 1)
        return (84);
    list_t *list = new_list();
    char **environ = env_copy(env);

    fill_env_list(list, environ);
    launch_prog(list, size);

    return 0;
}