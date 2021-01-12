/*
** EPITECH PROJECT, 2019
** torus.cpp
** File description:
** torus
*/

#include "torus.hpp"
torus::torus(char **argv)
{
    this->opt = atoi(argv[1]);
    this->a0 = atof(argv[2]);
    this->a1 = atof(argv[3]);
    this->a2 = atof(argv[4]);
    this->a3 = atof(argv[5]);
    this->a4 = atof(argv[6]);
    this->n = atof(argv[7]);
}

int torus::solver()
{
    if (this->opt == 1) {
        this->bisection();
        return (0);
    }
    if (this->opt == 2) {
        this->newton();
        return (0);
    }
    if (this->opt == 3) {
        this->secant();
        return (0);
    }
    return (84);
}

void torus::bisection()
{
    std::cout << "bisection" << std::endl;
    return ;
}

void torus::newton()
{
    std::cout << "newton" << std::endl;
    return ;
}

void torus::secant()
{
    std::cout << "secant" << std::endl;
    return ;
}

torus::~torus()
{
}