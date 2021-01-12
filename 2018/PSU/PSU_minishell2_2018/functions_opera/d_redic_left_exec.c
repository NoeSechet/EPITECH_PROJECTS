/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** d_redic_left_exec.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

char *get_input(char *stop_sig)
{
    char *final_out = NULL;
    char *input;
    size_t size;

    while (comp_word(input, stop_sig, my_strlen(stop_sig)) != 1) {
        if (getline(&input, &size, stdin) == -1)
            break;
        my_printf("%s\n", input);
        final_out = fusion(final_out, strcopy(input));
    }
    return (final_out);
}

int d_redic_left_exec(bin_tree_t *d_redic_node, list_t *list)
{
    (void)list;
    my_printf("double redic left detected\n");
    my_printf("%s\n", d_redic_node->right->command_parser);

    return (0);
}