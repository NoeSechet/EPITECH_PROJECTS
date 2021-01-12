/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** complete_node.c
*/

#include "utils_lem_in.h"

int check_node_presence(vertex_t *list_vertex, char **node_res)
{
    int presence_node_1 = 0;
    int presence_node_2 = 0;

    for (vertex_t *temp_vert = list_vertex; temp_vert != NULL;
    temp_vert = temp_vert->next) {
        if (str_n_comp(node_res[0], temp_vert->ID_vertex,
        my_strlen(temp_vert->ID_vertex)) == 1)
            presence_node_1 += 1;
        if (str_n_comp(node_res[1], temp_vert->ID_vertex,
        my_strlen(temp_vert->ID_vertex)) == 1)
            presence_node_2 += 1;
    }
    return (presence_node_1 == 1 && presence_node_2 == 1 ? 1 : -1);
}

char **check_node(graph_t *graph, char *node)
{
    int dash_presence = 0;
    char **node_result = NULL;

    if (node == NULL)
        return (NULL);
    for (int i = 0; node[i] != '\0'; i += 1) {
        if (node[i] == ' ')
            return (NULL);
        if (node[i] == '-')
            dash_presence += 1;
    }
    if (dash_presence != 1 ||
    (node_result = str_to_word_array(node, '-')) == NULL)
        return (NULL);
    if (check_node_presence(graph->list_vertex, node_result) == -1) {
        return (NULL);
    }
    my_printf("%s\n", node);
    return (node_result);
}

int complete_node(graph_t *graph, char **script_tab, int *i)
{
    char **connex = NULL;
    int start_end_pres = 0;

    my_printf("#tunnels\n");
    for (; script_tab[*i] != NULL; *i += 1)
        if (script_tab[*i][0] != '#') {
            if ((connex = check_node(graph, script_tab[*i])) == NULL) {
                return (-1);
            }
            start_end_pres += add_edge(graph, connex[0], connex[1]);
        }
    if (connex == NULL || start_end_pres < 2) {
        return (-1);
    }
    return (1);
}