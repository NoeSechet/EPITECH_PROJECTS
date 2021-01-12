/*
** EPITECH PROJECT, 2018
** entity_collide
** File description:
** entity_collide
*/

#include "utils.h"

int rect_point(entity_t *ent, float pos[2])
{
    if (pos[0] >= ent->x && pos[0] <= ent->x + ent->w
        && pos[1] >= ent->y && pos[1] <= ent->y + ent->h)
        return (1);
    return (0);
}

int circle_point(entity_t *ent, float pos[2])
{
    float dist = 0;
        if (pos[0] >= ent->x - ent->w && pos[0] <= ent->x + ent->w &&
            pos[1] >= ent->y - ent->w && pos[1] <= ent->y + ent->w) {
        dist = pow(ent->x - pos[0], 2)+
            pow(ent->y - pos[1], 2);

        if (dist <= pow(ent->w, 2))
            return (1);
    }
    return (0);
}

void rect_rect(entity_t *a, entity_t *b)
{
    int count = 0;

    if (a->collide == 0 || b->collide == 0) {
        count += rect_point(a, (float[2]) {b->x, b->y});
        count += rect_point(a, (float[2]) {b->x + b->w, b->y});
        count += rect_point(a, (float[2]) {b->x + b->w, b->y + b->h});
        count += rect_point(a, (float[2]) {b->x, b->y + b->h});

        if (count > 0) {
            a->collide = 1;
            b->collide = 1;
        }
    }
}

void circle_circle(entity_t *a, entity_t *b)
{
    float dist = 0;
    
    if ((a->collide == 0 || b->collide == 0) &&
        (abs(a->x - b->x) <= a->w + b->w && abs(a->y - b->y) < a->w + b->w)) {
        dist = pow(a->x - b->x, 2) + pow(a->y - b->y , 2);
        if (dist < pow(a->w + b->w, 2)) {
            a->collide = 1;
            b->collide = 1;
        }
    }
}

void circle_rect(entity_t *a, entity_t *b)
{
    int count = 0;

    if (a->collide == 0 || b->collide == 0) {
        count += circle_point(a, (float[2]) {b->x, b->y});
        count += circle_point(a, (float[2]) {b->x + b->w, b->y});
        count += circle_point(a, (float[2]) {b->x + b->w, b->y + b->h});
        count += circle_point(a, (float[2]) {b->x, b->y + b->h});

        count += rect_point(b, (float[2]) {a->x + a->w, a->y});
        count += rect_point(b, (float[2]) {a->x - a->w, a->y});
        count += rect_point(b, (float[2]) {a->x, a->y + a->w});
        count += rect_point(b, (float[2]) {a->x, a->y - a->w});

        if (count > 0) {
            a->collide = 1;
            b->collide = 1;
        }
    }
}