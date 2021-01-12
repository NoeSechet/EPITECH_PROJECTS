/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error.c
*/

#include "include/utils.h"

int check_boat_presence(char **map)
{
    int boat_box_count = 0;

    for (int i = 2; map[i] != NULL; i += 1) {
        for (int j = 2; map[i][j] != '\0'; j += 1) {
            if (map[i][j] != '.' && map[i][j] != ' ')
                boat_box_count += 1;
        }
    }
    return (boat_box_count == 14 ? 1 : 0);
}

int horizontal_boat(char *line)
{
    return ((line[2] == line[5] || line[3] == line[6]) ? 1 : 0);
}

int is_right_nbr(char n)
{
    return ((n >= 49 && n <= 56) ? 1 : 0);
}

int is_right_letter(char c)
{
    return ((c >= 65 && c <= 72) ? 1 : 0);
}

int check_error(char *line)
{
    if (my_strlen(line) != 7)
        return (0);
    if (is_right_letter(line[2]) == 0 || is_right_letter(line[5]) == 0 ||
        is_right_nbr(line[3]) == 0 || is_right_nbr(line[6]) == 0 ||
        horizontal_boat(line) == 0 || line[1] != ':' || line[4] != ':')
            return (0);
    return (1);
}