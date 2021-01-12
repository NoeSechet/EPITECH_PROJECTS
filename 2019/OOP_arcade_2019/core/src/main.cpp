/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** MAIN
*/

#include <iostream>

#include "Core.hpp"
#include "time.h"

std::string getUserName()
{
    std::string userName = "";

    std::cout << std::endl << "Enter your username : ";
    getline(std::cin, userName);
    if (userName.size() < 2 || userName.size() > 10) {
        std::cout << "Invalid size (minimum 2 and maximum 10 characters)." << std::endl;
        return getUserName();
    }
    return userName;
}

int print_usage()
{
    std::cout << "Usage: ./arcade ./[path to graphical shared library module]" << std::endl;
    return 84;
}

int main(int ac, const char *av[])
{
    srand (time(NULL));
    if (ac != 2)
        return print_usage();
    try {
        Core core(av[1], getUserName());
        core.loop();
    } catch(std::logic_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}