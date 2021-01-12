/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"

void echo_print(char **args, main_list_t *list, int *flags)
{
    int i = 1;

    for (; args[i + 1] != NULL; i++) {
        if (is_flag(args[i]) == true)
            continue;
        if (strlen(args[i]) > 1 && args[i][0] == '$') {
            echo_dollars(args[i], list, true);
            continue;
        }
        my_printf("%s ", args[i]);
    }
    if (strlen(args[i]) > 1 && args[i][0] == '$')
        echo_dollars(args[i], list, false);
    else if (is_flag(args[i]) == false)
        my_printf("%s", args[i]);
    flags[n_flag] == true ? 0 : my_printf("\n");
}

int my_echo(main_list_t *list, tree_t *tree, char **args)
{
    (void)tree;
    int *flags = get_flags(args);

    if (echo_error(args, flags, list) == 1)
        return (1);
    if (get_nb_str_array(args) == 1) {
        my_printf("\n");
        free(flags);
        return (0);
    }
    echo_print(args, list, flags);
    free(flags);
    list->value_return = 0;
    return (0);
}