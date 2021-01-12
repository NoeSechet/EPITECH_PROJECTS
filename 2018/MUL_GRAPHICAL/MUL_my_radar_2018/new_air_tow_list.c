/*
** EPITECH PROJECT, 2018
** new_air_tow_list.c
** File description:
** new_air_tow_list.c
*/

#include "utils.h"

air_list_t *new_air_list(void)
{
    air_list_t *air_list;

    air_list = malloc(sizeof(air_list_t));

    air_list->length = 0;
    air_list->start = NULL;
    air_list->end = NULL;
    return (air_list);
}

tow_list_t *new_tow_list(void)
{
    tow_list_t *tow_list;

    tow_list = malloc(sizeof(tow_list_t));

    tow_list->length = 0;
    tow_list->start = NULL;
    tow_list->end = NULL;
    return (tow_list);
}