/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** foreach
*/

#include "mysh.h"
#include "env_loc.h"

int error_foreach(char **input);

arraylist_t *read_inside_foreach(arraylist_t *list)
{
    char *buf = NULL;
    int er = 0;
    size_t n = 0;

    if (isatty(0))
        write (1, "foreach? ", 9);
    er = getline(&buf, &n, stdin);
    while (my_strcmp(buf, "end\n") != 0 &&
        my_strcmp(buf, "end\0") != 0 && er != -1) {
        n = 0;
        for (int i = 0; buf[i]; i++)
            buf[i] = buf[i] == '\n' ? '\0' : buf[i];
        add_elem(list, create_new_node(buf));
        free (buf);
        if (isatty(0))
            write (1, "foreach? ", 9);
        er = getline(&buf, &n, stdin);
    }
    free (buf);
    return (list);
}

void foreach_var(char *var, char *input, char **line, main_list_t *main)
{
    int len = my_strlen(input);

    input[len - 1] = input[len - 1] == ')' ? '\0' : input[len - 1];
    for (int h = 0; line[h]; h++) {
        if (is_exist(var, main))
            update_value_env_loc(var, input, main);
        else
            add_env_local(main, var, input);
        }
}

void clear_input(char **input, int *i)
{
    int u = 0;

    while (input[*i][u] == '(' || input[*i][u] == ')' || input[*i][u] == ' ') {
        u++;
        if (input[*i][u] == '\0' && input[*i + 1] == NULL)
            return;
        if (input[*i][u] == '\0') {
            *i += 1;
            u = 0;
        }
    }
}

void exec_foreach(main_list_t *main, char **input,
    arraylist_t *list)
{
    int len = my_tablen(input);

    if (input[len - 1][0] == ')')
        len--;
    for (int i = 2; i < len; i++) {
        clear_input(input, &i);
        for (int j = 0; j < list->nb_elem; j++) {
            foreach_var(input[1], input[i], (char **)list->array[j], main);
            do_execution((tree_t *)list->array[j], main);
        }
    }
}

int my_foreach(main_list_t *main, tree_t *tree, char **input)
{
    arraylist_t *list = NULL;

    (void)tree;
    if (error_foreach(input))
        return (1);
    list = create_list(1);
    list = read_inside_foreach(list);
    exec_foreach(main, input, list);
    for (int x = 0; x < list->nb_elem; x++)
        destroy_tree((tree_t *)list->array[x]);
    free(list->array);
    free(list);
    return (0);
}
