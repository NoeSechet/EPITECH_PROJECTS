/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#include "arraylist.h"
#include "entity.h"

sfCircleShape *create_circle(sfVector2f position, float radius);
sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size);
void destroy_shapes(void **shapes);

#endif