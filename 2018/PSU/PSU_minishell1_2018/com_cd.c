/*
** EPITECH PROJECT, 2019
** com_cd.c
** File description:
** com_cd.c
*/

#include "include/utils.h"

void check_cd_error(char *path)
{
    if (access(path, F_OK) == 0)
        my_printf("%s: Not a directory.\n", path);
    else if (comp_word_right(path, "-", my_strlen(path)) == 1) {
        my_printf(" : No such file or directory.\n");
    } else
        my_printf("%s: No such file or directory.\n", path);
}

void cd_with_path(char *path, list_t *list)
{
    char cwd[4096];
    char pwd[4096];
    char *OLD_PWD = getcwd(pwd, 4096);

    if (comp_word_right(get_environment_val("PWD", list),
    get_environment_val("OLDPWD", list),
    my_strlen(OLD_PWD)) != 1 && comp_word(path, "-", my_strlen(path)) == 1)
        chdir(get_environment_val("OLDPWD", list));
    else if (chdir(path) == -1 ||
    (comp_word_right(get_environment_val("PWD", list),
    get_environment_val("OLDPWD", list),
    my_strlen(OLD_PWD)) == 1 &&
    comp_word_right(path, "-", my_strlen(path)) == 1))
        check_cd_error(path);

    update_newpwd("PWD", getcwd(cwd, 4096), list);
    update_oldpwd("OLDPWD", OLD_PWD, list);
}

void simple_cd(list_t *list, char *path)
{
    char *value = get_environment_val("HOME", list);
    chdir(value);
    if (comp_word(path, "home", 4) == 1)
        my_printf("~ \n");
}

int com_cd(char **tab, list_t *list, char **environ)
{
    (void)environ;
    int word_count = 0;

    for (int i = 0; tab[i] != NULL; i += 1, word_count += 1);

    if (word_count > 2) {
        my_printf("cd: Too many arguments.\n");
        return (0);
    }
    if (word_count == 1 || (word_count == 2 &&
    (comp_word(tab[1], "home", 4) == 1 ||
    comp_word(tab[1], "~", 1) == 1))) {
        simple_cd(list, tab[1]);
    } else {
        cd_with_path(tab[1], list);
    }
    return (0);
}