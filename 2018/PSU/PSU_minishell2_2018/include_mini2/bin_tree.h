/*
** EPITECH PROJECT, 2019
** binary_tree.h
** File description:
** binary_tree.h
*/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct bin_tree_s {
    int save_fd;
    int *fd;
    char *command_parser;
    struct bin_tree_s *left;
    struct bin_tree_s *right;
} bin_tree_t;

typedef struct tree_operator_s {
    char *op;
    int (*functPointer)(bin_tree_t *node, list_t *list);
} tree_operator_t;

void print_bin_tree(bin_tree_t *bin_tree);

bin_tree_t *create_new_node(char *opera_node);

int complete_bin_tree(bin_tree_t *bin_tree, char *input);
int opera_present(char *input, char *opera);
char **opera_sep(char *input, char *opera);

int add_new_opera_node(bin_tree_t *last_node, char **opera_node, char *opera);

// ---- EXECUTE BIN_TREE ---- //
int execute_bin_tree(bin_tree_t *bin_tree, list_t *list);

int semi_col_exec(bin_tree_t *node, list_t *list);
int d_redic_right_exec(bin_tree_t *node, list_t *list);
int d_redic_left_exec(bin_tree_t *node, list_t *list);
int redic_left_exec(bin_tree_t *node, list_t *list);
int redic_right_exec(bin_tree_t *node, list_t *list);
int pipe_exec(bin_tree_t *node, list_t *list);


#endif /* !BINARY_TREE_H_ */