/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** launch
*/

#include "objd.h"

int launch_f_objd(int ac, int nbr_file, char **av_cop)
{
    int res = 0;

    if (nbr_file == 0) {
        return get_f_info("a.out");
    } else if (nbr_file > 0) {
        for (int i = 1; i < ac; i += 1) {
            av_cop[i][0] != '-' ? (res = get_f_info(av_cop[i])) : 0;
        }
    }
    return res;
}

int launch_s_objd(int ac, int nbr_file, char **av_cop)
{
    int res = 0;

    if (nbr_file == 0) {
        return get_s_info("a.out");
    } else if (nbr_file > 0) {
        for (int i = 1; i < ac; i += 1) {
            av_cop[i][0] != '-' ? (res = get_s_info(av_cop[i])) : 0;
        }
    }
    return res;
}

int launch_f_s_objd(int ac, int nbr_file, char **av_cop)
{
    int res = 0;

    if (nbr_file == 0) {
        return get_s_info("a.out");
    } else if (nbr_file > 0) {
        for (int i = 1; i < ac; i += 1) {
            av_cop[i][0] != '-' ? (res = get_f_s_info(av_cop[i])) : 0;
        }
    }
    return 0;
}