/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** vertex_error.c
*/

#include "utils_lem_in.h"

char *check_vertex(char *vertex_line, int start_end)
{
    if (vertex_line == NULL)
        return (NULL);

    if (start_end == 1 && (vertex_line[0] > '9' || vertex_line[0] < '0'))
        return (NULL);

    for (int i = 0; vertex_line[i] != '\0'; i += 1) {
        if (vertex_line[i] == '-')
            return (NULL);
    }
    return (str_to_word_array(vertex_line, ' ')[0]);
}

int is_start_end(char *vertex)
{
    if (str_n_comp(vertex, "##start", my_strlen(vertex)) == 1) {
        return (1);
    } else if (str_n_comp(vertex, "##end", my_strlen(vertex)) == 1) {
        return (2);
    } else {
        return (0);
    }
}

int add_start_end(graph_t *graph, char *vertex, int start_end_index,
int *start_end_counter)
{
    if (vertex == NULL)
        return (-1);
    if (start_end_index == 1) {
        my_printf("##start\n");
        add_vertex(graph, vertex, start);
        start_end_counter[0] += 1;
    } else {
        my_printf("##end\n");
        add_vertex(graph, vertex, end);
        start_end_counter[1] += 1;
    }
    return (1);
}

int *init_start_end_counter(void)
{
    int *start_end_counter = malloc(sizeof(int) * 2);

    start_end_counter[0] = 0;
    start_end_counter[1] = 0;

    return (start_end_counter);
}

int complete_vertex(graph_t *graph, char **script_tab, int *i)
{
    char *vertex = NULL;
    int start_end_index = 0;
    int *start_end_counter = init_start_end_counter();

    my_printf("#rooms\n");
    for (int j = 0; (vertex = check_vertex(script_tab[*i], 0)) != NULL;
    *i += 1, j += 1) {
        if ((start_end_index = is_start_end(vertex)) != 0) {
            if (add_start_end(graph, check_vertex(script_tab[*i + 1], 1),
            start_end_index, start_end_counter) == -1)
                return (-1);
            *i += 1;
            my_printf("%s\n", script_tab[*i]);
        } else if (vertex[0] != '#') {
            add_vertex(graph, vertex, lambda);
            my_printf("%s\n", script_tab[*i]);
        }
    }
    if (start_end_counter[0] == 1 && start_end_counter[1] == 1) return (1);
    return (-1);
}