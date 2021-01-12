/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** create_env
*/

#include "mysh.h"

void create_new_env(list_t *list)
{
    char *path1 =
    "PATH=/home/la-montagne/bin:/home/la-montagne/.local/bin:/usr/local/sbin:";
    char *path2 =
    "/usr/local/bin:/usr/sbin:/usr/bin:/sbin:";
    char *path3 = "/bin:/usr/games:/usr/local/games:/snap/bin";
    char *path = my_strcat(path1, path2);
    char *term = "TERM=xterm-256color";
    char *pwd = malloc(sizeof(char) * 4096);

    path = my_strcat(path, path3);
    pwd = getcwd(pwd, 4096);
    push_back_haroun(list, path);
    push_back_haroun(list, term);
    push_back_haroun(list, my_strcat("PWD=", pwd));
}
