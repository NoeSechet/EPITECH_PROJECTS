/*
** EPITECH PROJECT, 2018
** fill_tower_list.c
** File description:
** fill_tower_list.c
*/

#include "utils.h"

tow_list_t *fill_tower_list(tow_list_t *tow_list, int *decomp_info,
void *circle)
{
    tower_t *tower = malloc(sizeof(aircraft_t));
    tower->id = 1;
    tower->pos = (sfVector2f){decomp_info[0], decomp_info[1]};
    tower->rad = decomp_info[2];
    tower->shape = circle;
    tower->previous = NULL;
    tower->next = NULL;

    if (tow_list->length == 0) {
        tow_list->start = tower;
        tow_list->end = tower;
    } else {
        tower->previous = tow_list->end;
        tow_list->end->next = tower;
        tow_list->end = tower;
    }
    tow_list->length += 1;
    return (tow_list);
}