/*
** EPITECH PROJECT, 2019
** update_position.c
** File description:
** update_position.c
*/

#include "utils.h"

void remove_temp(air_list_t *air_list, aircraft_t *temp)
{
    if (temp->previous != NULL)
        temp->previous->next = temp->next;
    else
        air_list->start = temp->next;
    if (temp->next != NULL)
        temp->next->previous = temp->previous;
    else
        air_list->end = temp->previous;
    temp->next = NULL;
    temp->previous = NULL;
    free(temp);
    temp = NULL;

    air_list->length -= 1;
}

void update_tab_position(air_list_t *air_list, air_list_t **tab_list,
int index)
{
    (void)tab_list;
    int size_W = 2;
    int size_H = 2;
    int width = 1920 / size_W;
    int height = 1080 / size_H;
    int x = 0;
    int y = 0;

    for (aircraft_t *temp = air_list->start; temp != NULL; temp = temp->next) {
        x = temp->a.x / width;
        y = temp->a.y / height;
        if ((x + y * size_W) != index) {
            tab_list[x + y * size_W] = fill_tab_list(tab_list[x + y * size_W],
            temp);
            remove_temp(air_list, temp);
        }
    }
}