/*
** EPITECH PROJECT, 2019
** create_shapes.c
** File description:
** create_shapes.c
*/

#include "utils.h"

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, sfBlack);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setPosition(circle, position);
    return (circle);
}

sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangle, sfBlack);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setPosition(rectangle, position);
    return (rectangle);
}

void destroy_shapes(void **shapes)
{
    sfRectangleShape_destroy(shapes[0]);
    sfCircleShape_destroy(shapes[1]);
}