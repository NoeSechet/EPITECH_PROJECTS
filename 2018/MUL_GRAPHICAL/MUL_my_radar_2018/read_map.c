/*
** EPITECH PROJECT, 2018
** read_map.c
** File description:
** read_map.c
*/

#include "utils.h"

int get_next_num(char *line, int *i)
{
    int next_num = 0;

    for (; line[*i] > '9' && line[*i] < '0'; *i += 1);
    while (line[*i] >= 48 && line[*i] <= 57) {
        next_num = next_num * 10 + line[*i] - 48;
        *i += 1;
    }
    return (next_num);
}

int *decompose_info(char *line, char plane_or_tower)
{
    (void)line;
    int *decomp_info;
    int num = 0;

    if (plane_or_tower == 'A')
        decomp_info = malloc(sizeof(int) * 6);
    else if (plane_or_tower == 'T')
        decomp_info = malloc(sizeof(int) * 3);
    else
        return (NULL);
    for (int i = 2; line[i] != '\0' && line[i] != '\n'; i += 1) {
        decomp_info[num] = get_next_num(line, &i);
        num += 1;
    }
    return (decomp_info);
}

void check_type(char *line, air_list_t *air_list, tow_list_t *tow_list,
void **shapes)
{
    int *decomp_info;
    if (line != NULL) {
        if (line[0] == 'A') {
            decomp_info = decompose_info(line, line[0]);
            air_list = fill_aircraft_list(air_list, decomp_info, shapes[0]);
        } else if (line[0] == 'T') {
            decomp_info = decompose_info(line, line[0]);
            tow_list = fill_tower_list(tow_list, decomp_info, shapes[1]);
        }
    }
}

int read_map(char *file, air_list_t *air_list, tow_list_t *tow_list,
void **shapes)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t len_read = 0;

    FILE *str = fopen(file, "r");
    if (str == NULL)
        return (1);
    while ((len_read = getline(&line, &size, str)) > 0) {
        line[len_read] = '\0';
        check_type(line, air_list, tow_list, shapes);
    }
    free(line);
    fclose(str);
    return (0);
}