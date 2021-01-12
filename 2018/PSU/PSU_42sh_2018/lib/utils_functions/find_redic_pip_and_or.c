/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** find_redic_pip_and_or.c
*/

int my_strcmp(char *s1, char *s2);

int find_redirection(char *str)
{
    if (my_strcmp(str, ">") == 0 || my_strcmp(str, ">>") == 0 ||
        my_strcmp(str, "<") == 0 || my_strcmp(str, "<<") == 0)
        return (0);
    return (1);
}

int find_pipes(char *str)
{
    if (my_strcmp(str, "|") == 0)
        return (0);
    return (1);
}

int find_and_or_or(char *str)
{
    if (my_strcmp(str, "||") == 0 || my_strcmp(str, "&&") == 0)
        return (0);
    return (1);
}