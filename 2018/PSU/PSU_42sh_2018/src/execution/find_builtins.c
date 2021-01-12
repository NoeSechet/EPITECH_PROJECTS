/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** find builtins
*/

#include "mysh.h"

static const pointeur_t pointeur_g[] = {
    {"setenv", &my_setenv},
    {"history", &my_history},
    {"env", &my_env},
    {"exit", &my_exit},
    {"cd", &my_cd},
    {"unsetenv", &my_unsetenv},
    {"echo", &my_echo},
    {"which", &my_which},
    {"where", &my_where},
    {"foreach", &my_foreach},
    {"set", &my_set},
    {"unset", &my_unset},
    {"repeat", &my_repeat},
    {"alias", &my_alias},
    {"unalias", &my_unalias},
    {NULL, NULL}
};

void check_dup(tree_t *tree, int *fptr)
{
    close(tree->fd[0]);
    close(tree->fd[1]);
    if (dup2(fptr[0], 0) == -1 || dup2(fptr[1], 1) == -1)
        return;
}

int find_builtin(main_list_t *main, char **inp, tree_t *tree)
{
    int fptr[2];

    if (!inp)
        return (0);
    fptr[0] = dup(0);
    fptr[1] = dup(1);
    for (int x = 0, ret = 0; pointeur_g[x].name != NULL; x++)
        if (my_strcmp(inp[0], pointeur_g[x].name) == 0) {
            dup2(tree->fd[0], 0);
            dup2(tree->fd[1], 1);
            ret = pointeur_g[x].pointeur(main, tree, inp);
            check_dup(tree, fptr);
            return (ret);
        }
    return (-1);
}

int is_buildin(char *cmd)
{
    int i = 0;

    while (pointeur_g[i].name) {
        if (my_strcmp(cmd, pointeur_g[i].name) == 0)
            return (1);
        i++;
    }
    return (0);
}