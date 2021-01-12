/*
** EPITECH PROJECT, 2018
** instructions.c
** File description:
** instructions
*/

#include "utils.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] && s2[i] && i < n; i += 1)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

void instructions(void)
{
    my_putstr("Air traffic simulation panel\n\nUSAGE\n");
    my_putstr("./my_radar [OPTIONS] path_to_script\n");
    my_putstr("path_to_script      The path to the script file.\n");
    my_putstr("The script must have the following format:\n");
    my_putstr("For planes:\n    X1 X2 Y1 Y2 SPEED TAKE_OFF_TIME\n");
    my_putstr("\n    X1 and X2 being the starting and ending X coordinates");
    my_putstr(" of the plane.\n");
    my_putstr("    Y1 and Y2 being the starting and ending Y coordinates of");
    my_putstr(" the plane.\n");
    my_putstr("    SPEED being the speed of the plane in pixel/second.\n");
    my_putstr("    TAKE_OFF_TIME Being the elapsed time before the plane ");
    my_putstr("takes off.\n");
    my_putstr("\nFor towers:\n    X Y RAD\n");
    my_putstr("\n    X and Y being the X and Y coordinates of the tower ");
    my_putstr("position.\n");
    my_putstr("    RAD being the raiuds of the tower range in pixels.\n");
    my_putstr("\nOPTIONS\n-h                prints the usage and quits\n\n");
    my_putstr("USER INTERACTIONS\nESC_KEY        quits the program.\n");
}