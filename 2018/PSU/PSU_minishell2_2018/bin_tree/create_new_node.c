/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** init_bin_tree.c
*/

#include "utils_mini2.h"
#include "bin_tree.h"

char *clean_input(char *input)
{
    char *final_input = NULL;
    int i = 0;

    for (; input[0] == ' ' || input[0] == '\t'; input += 1);

    for (i = my_strlen(input) - 1;
    input[i] == ' ' ||
    input[i] == '\t'; i -= 1);

    final_input = malloc(sizeof(char) * (i + 2));

    for (int k = 0; k < i + 2; k += 1) {
        final_input[k] = input[k];
    }
    final_input[i + 1] = '\0';
    return (final_input);
}

int *create_fd(void)
{
    int *fd = malloc(sizeof(int) * 2);

    fd[0] = 0;
    fd[1] = 1;

    return (fd);
}

bin_tree_t *create_new_node(char *opera_node)
{
    bin_tree_t *bin_tree = malloc(sizeof(bin_tree_t));

    bin_tree->fd = create_fd();

    bin_tree->command_parser = clean_input(opera_node);
    bin_tree->left = NULL;
    bin_tree->right = NULL;

    return (bin_tree);
}