/*
** EPITECH PROJECT, 2018
** bonus pong
** File description:
** bonus pong.h
*/

#ifndef BONUS_H
#define BONUS_H


#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>

typedef struct brick_s
{
    int x;
    int y;
    int hp;
    sfTexture *txt;
    sfSprite *spr;
    int update;
} brick_t;

sfVector2f fill_vector(int x, int y);
void draw_ball(sfRenderWindow *window, sfVector2f *ball_coord,
    sfVector2f *ball_Velocity, sfVector2f bat_coord);
void back_draw(sfRenderWindow *window);
brick_t **fill_wall(void);
void draw_wall(sfRenderWindow *window, sfVector2f *ball_coord,
    sfVector2f *ball_Velocity, brick_t **brick);

#endif