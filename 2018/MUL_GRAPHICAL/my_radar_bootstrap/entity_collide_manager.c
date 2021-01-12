/*
** EPITECH PROJECT, 2018
** entity_collide_manager
** File description:
** entity_collide_manager
*/

#include "utils.h"

void entity_collide(entity_t *a, entity_t *b)
{
    if (a != NULL && b != NULL) {
        if (a->id == 0 && b->id == 0)
            rect_rect(a, b);
        if (a->id != b->id)
            circle_rect(a->id == 1 ? a : b, a->id == 1 ? b : a);
        if (a->id == 1 && b->id == 1)
            circle_circle(a, b);
    }
}

void collide(arraylist_t *entities, int i, int j)
{
    if (i != j)
        entity_collide(arraylist_get(entities, i), arraylist_get(entities, j));
}

void check_collision(arraylist_t *entities)
{
    for (int i = 0; i < entities->size; i++)
        for (int j = 0; j < entities->size; j++)
            collide(entities, i, j);
}