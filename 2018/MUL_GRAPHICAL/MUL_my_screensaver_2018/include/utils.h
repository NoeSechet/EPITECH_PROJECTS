/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <math.h>
#include <time.h>
#include <SFML/Window/Export.h>
#include <stdio.h>
#include <unistd.h>

#include "main_struct.h"

typedef unsigned int uint;

int analyse_events(char **av, spritext_t *spritext);
sfRenderWindow *window_create(int width, int height);
frame_t *framebuffer_create(uint width, uint height);
spritext_t *fill_spritext(void);
main_t *fill_main_struct(void);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_random(int min, int max);

void first_anim(main_t *main_s, spritext_t *spritext);
void put_pixel(frame_t *buf, int x, int y, sfColor color);
void sec_anim(main_t *main_s, spritext_t *spritext);
void draw_line(frame_t *buf, rays_t rays);
void third_anim(main_t *main_s, spritext_t *spritext);
void draw_discs(frame_t *buf, discs_t discs);
void draw_circle(frame_t *buf, circles_t circles);
void fourth_anim(main_t *main_s, spritext_t *spritext);
void fifth_anim(main_t *mains, spritext_t *spritext);
void put_circle(int coord_x, int coord_y, int radius, frame_t *buf);
void h_instructions(void);
void d_instructions(void);

#endif /* !UTILS_H_ */