/*
** EPITECH PROJECT, 2018
** CPE_lemin_2018
** File description:
** read_script.c
*/

#include "utils_lem_in.h"

graph_t *create_graph(void)
{
    graph_t *graph = init_graph();
    char *line = NULL;
    size_t size = 0;
    char *script = NULL;
    char **script_tab = NULL;

    for (int index = 0; getline(&line, &size, stdin) > 0; index += 1) {
        if (index == 0)
            script = strcopy(line);
        else if (index > 0)
            script = fusion(script, line);
    }

    if (script == NULL)
        return (NULL);
    script_tab = str_to_word_array(script, '\n');
    if (complete_graph(graph, script_tab) == -1)
        return (NULL);
    return (graph);
}