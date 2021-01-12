/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** complete_graph.c
*/

#include "utils_lem_in.h"

int check_nb_ant(char **script_tab, int *i)
{
    for (; script_tab[*i][0] == '#'; *i += 1);

    for (int j = 0; script_tab[*i][j] != '\0'; j += 1) {
        if (script_tab[*i][j] < '0' || script_tab[*i][j] > '9') {
            return (-1);
        }
    }
    return (my_getnbr(script_tab[*i]));
}

int complete_graph(graph_t *graph, char **script_tab)
{
    int i = 0;

    if ((graph->nb_ants = check_nb_ant(script_tab, &i)) == -1)
        return (-1);
    i += 1;
    my_printf("#number_of_ants\n%d\n", graph->nb_ants);
    if (complete_vertex(graph, script_tab, &i) == -1)
        return (-1);
    if (complete_node(graph, script_tab, &i) == -1)
        return (-1);
    if (script_tab[i] != NULL)
        return (-1);

    return (1);
}