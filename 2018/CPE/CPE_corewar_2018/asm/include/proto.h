/*
** EPITECH PROJECT, 2019
** proto
** File description:
** proto
*/

#ifndef PROTO_H
#define PROTO_H

#include "lib.h"
#include "utils.h"

int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
int strlenght(char const *str);
int getnbr(char *str, int i);
// int count_word(char *str);
// char **fill_line(char *str, int word);
void free_line(char **line);
void write_instruction(data_t *vector, char *file);
char *copycat(char const *s1, char const *s2, int n);

void coding_byte(int i, char *line, int fd);
void instruction_arg(int i, char *line, int fd, data_t *data);

#endif