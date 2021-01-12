/*
** EPITECH PROJECT, 2018
** entity_draw
** File description:
** entity_draw
*/

#include "utils.h"

void draw_rect(sfRenderWindow *win, entity_t *ent)
{
    sfRectangleShape *rect = (sfRectangleShape *)ent->shape;
    
    sfRectangleShape_setPosition(rect, (sfVector2f){ent->x, ent->y});
    sfRectangleShape_setSize(rect, (sfVector2f){ent->w, ent->h});
    if (ent->collide)
        sfRectangleShape_setFillColor(rect, ent->color);
    else
        sfRectangleShape_setFillColor(rect, sfColor_fromInteger(0));
    sfRenderWindow_drawRectangleShape(win, rect, NULL);
}

void draw_circle(sfRenderWindow *win, entity_t *ent)
{
    sfCircleShape *circle = (sfCircleShape *)ent->shape; 

    sfCircleShape_setRadius(circle, ent->w);
    sfCircleShape_setPosition(circle, (sfVector2f){ent->x - ent->w, ent->y - ent->w});
    if (ent->collide)
        sfCircleShape_setFillColor(circle, ent->color);
    else
        sfCircleShape_setFillColor(circle, sfColor_fromInteger(0));
    sfRenderWindow_drawCircleShape(win, circle, NULL);
}

void draw_entity(sfRenderWindow *win, entity_t *ent)
{
    if (ent == NULL)
        return;
    switch (ent->id) {
        case 0:
            draw_rect(win, ent);
            break;
        case 1:
            draw_circle(win, ent);
            break;            
        default:
        break;
    }
}

void draw_entities(sfRenderWindow *win, arraylist_t *entities, int reset)
{
    for (int i = 0; i < entities->size; i++) {
        draw_entity(win, (entity_t *)arraylist_get(entities, i));
        if (reset && arraylist_get(entities, i) != NULL) {
            ((entity_t *)arraylist_get(entities, i))->collide = 0;
        }
    }
}