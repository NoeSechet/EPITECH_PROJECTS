/*
** EPITECH PROJECT, 2018
** pong.h
** File description:
** pong header
*/

#ifndef PONG_H
#define PONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>

typedef struct ball_s
{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    int t;
} ball_t;

#endif