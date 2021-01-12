/*
** EPITECH PROJECT, 2018
** CPE_lemin_2018
** File description:
** main.c
*/

#include "utils_lem_in.h"

void move_ant(box_t *path, int *ants_on_end)
{
    path->status = not_available;
    path->previous->status = available;
    path->ID_ant = path->previous->ID_ant;
    path->previous->ID_ant = 0;
    my_printf("P%d-%s", path->ID_ant, path->ID_box);
    if (path->role == end)
        *ants_on_end += 1;
}

void is_print_space(int *index_space)
{
    if (*index_space > 0)
        my_printf(" ");
    *index_space += 1;
}

int send_ant_to_path(int *ants_on_end, ll_box_t *list_box, int ID_ants_send,
int total_ants)
{
    int index_space_2 = 0;

    if (ID_ants_send <= total_ants ) {
        list_box->start->status = not_available;
        list_box->start->ID_ant = ID_ants_send;
    } else {
        list_box->start->status = available;
        list_box->start->ID_ant = 0;
    }
    for (box_t *temp = list_box->end; temp->previous != NULL;
    temp = temp->previous)
        if ((temp->status == available || temp->role == end) &&
        temp->previous->status == not_available) {
            is_print_space(&index_space_2);
            move_ant(temp, ants_on_end);
        }
    if (index_space_2 == 0)
        return (-1);
    return (1);
}

void print_ants_movement(int total_ants, path_t *list_path)
{
    int ants_on_end = 0;
    int ID_ants_send = 1;
    int index_space = 0;

    my_printf("#moves\n");

    while (ants_on_end != total_ants) {
        for (path_t *temp = list_path; temp != NULL; temp = temp->next) {
            is_print_space(&index_space);
            if (send_ant_to_path(&ants_on_end, temp->list_box, ID_ants_send,
            total_ants) == -1)
                index_space = 0;
            ID_ants_send += 1;
        }
        index_space = 0;
        my_printf("\n");
    }
}

int main(void)
{
    graph_t *graph = NULL;
    ll_path_t *list_path = NULL;

    if ((graph = create_graph()) == NULL)
        return (84);

    if ((list_path = create_list_path(graph)) == NULL)
        return (84);

    print_ants_movement(graph->nb_ants, list_path->start);
    free_graph(graph);
    return (0);
}