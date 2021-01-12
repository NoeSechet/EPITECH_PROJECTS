/*
** EPITECH PROJECT, 2018
** instructions.c
** File description:
** instructions
*/

#include "utils.h"

void h_instructions(void)
{
    write(1, "animation rendering in a CSFML window\n\n", 39);
    write(1, "USAGE\n", 6);
    write(1, "./my_screensaver [OPTIONS] animation_id\n", 40);
    write(1, "animation_id      ID of the animetion to process", 48);
    write(1, "(between 1 and 20).\n\n", 21);
    write(1, "OPTIONS\n", 8);
    write(1, "-d                ", 18);
    write(1, "print the description of all the animations and quit.\n", 54);
    write(1, "-h                ", 18);
    write(1, "print the usage and quit\n\n", 26);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "LEFT_ARROW        switch to the previous animation.\n", 52);
    write(1, "RIGHT_ARROW       switch to the next animation.\n", 48);
}

void d_instructions(void)
{
    write(1, "1: A single pixel, that's MARVELOUS\n", 36);
    write(1, "2: one line, that doesn't even move LUL\n", 40);
    write(1, "3: a snake eating itself after some time has passed\n", 52);
}