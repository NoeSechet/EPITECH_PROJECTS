/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#define PARS_TAB_COND tab_list[i] != NULL && tab_list[i]->start != NULL

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "airline.h"

void draw_rect(sfRenderWindow *win);
int my_get_nbr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
void instructions(void);
air_list_t *new_air_list(void);
tow_list_t *new_tow_list(void);
sfCircleShape *create_circle(sfVector2f position, float radius);
sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size);

air_list_t *fill_aircraft_list(air_list_t *air_list, int *decomp_info,
    void *rect);
tow_list_t *fill_tower_list(tow_list_t *tow_list, int *decomp_info,
    void *circle);
int read_map(char *file, air_list_t *air_list, tow_list_t *tow_list,
    void **shapes);
air_list_t **cut_screen(int size[2], int w, int h, air_list_t *air_list);
void check_collision(air_list_t *air_list);

void draw_towers(sfRenderWindow *window, tow_list_t *tow_list);
void draw_planes(sfRenderWindow *window, air_list_t *air_list, sfClock
    *my_clock, sfClock *my_clock_launch);
void update_tab_position(air_list_t *air_list, air_list_t **tab_list,
int index);
void remove_temp(air_list_t *air_list, aircraft_t *temp);
air_list_t *fill_tab_list(air_list_t *tab_list, aircraft_t *temp_plane);

#endif /* !UTILS_H_ */