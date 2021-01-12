/*
** EPITECH PROJECT, 2018
** airline.h
** File description:
** airline
*/

#ifndef AIRLINE_H_
#define AIRLINE_H_

#include "utils.h"

typedef struct aircraft_s {
    int id;
    sfVector2f a;
    sfVector2f b;
    float pps;
    sfInt64 t_off;
    void *shape;
    int collide;
    struct aircraft_s *previous;
    struct aircraft_s *next;
} aircraft_t;

typedef struct tower_s {
    int id;
    sfVector2f pos;
    int rad;
    void *shape;
    struct tower_s *previous;
    struct tower_s *next;
} tower_t;

typedef struct air_list_s {
    int length;
    aircraft_t *start;
    aircraft_t *end;
} air_list_t;

typedef struct tow_list_s {
    int length;
    tower_t *start;
    tower_t *end;
} tow_list_t;

#endif /* !AIRLINE_H_ */