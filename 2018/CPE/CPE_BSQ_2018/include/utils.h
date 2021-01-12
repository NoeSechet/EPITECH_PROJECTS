/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errors.h>
#include <stdlib.h>
#include "struct_coords.h"

#ifndef UTILS_H
#define UTILS_H

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *);
int min(int a, int b);
void stops_program(char *buf, coord_t *Sq_coords);
void clean_buf(char **buf, coord_t *Sq_coords, int *nbr_first_line);
void charac_clone(char *buf, int *lineLength, int *nbr_int, int *line_nbr);
int *initiate_clone(char *buf, int *nbr_int);
void fill_struct(coord_t *Sq_coords, int *clone);
int check_coords(int x, int y, int *lineLength);
int square_coords(coord_t *Sq_coords, int x, int y, int *lineLength);
void set_coord(int *lineLength, int *line_nbr, coord_t *Sq_coords);
int single_point_square(char *buf);
void final_square(char *buf, coord_t *Sq_coords, int lineLength);

#endif