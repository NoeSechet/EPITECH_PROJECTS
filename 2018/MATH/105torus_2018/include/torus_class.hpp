/*
** EPITECH PROJECT, 2019
** torus class
** File description:
** torus_class
*/

class torus {
    public:
    torus(char **argv);
    int solver();
    ~torus();
    private:
    int opt;
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
    double n;
    void bisection();
    void newton();
    void secant();
};