/*
** EPITECH PROJECT, 2019
** draw_towers.c
** File description:
** draw_towers.c
*/

#include "utils.h"

void draw_circle(sfRenderWindow *window, tower_t *tower)
{
    sfCircleShape *circle = (sfCircleShape *)tower->shape;

    sfCircleShape_setRadius(circle, tower->rad);
    sfCircleShape_setPosition(circle, tower->pos);
    sfRenderWindow_drawCircleShape(window, circle, NULL);
}

void draw_towers(sfRenderWindow *window, tow_list_t *tow_list)
{
    tower_t *temp = tow_list->start;

    while (temp != NULL) {
        draw_circle(window, temp);
        temp = temp->next;
    }
}