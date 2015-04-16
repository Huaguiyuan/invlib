#ifndef W1D_H
#define W1D_H
#include "s.h"
#include "pc.h"
#include <vector>
#include <iostream>

class wind1D
{
    private:
    std::vector<double> pVec;
    std::vector<double> pVecShift;
    double windN;
    double mingap;


    public:
    wind1D( momSpace momS, coeffVec coeffV );
    void linspace(double pmin, double pmax, int pint);
    void printWind() {std::cout << windN;}
    double getWind() {return windN;}
    double getgapmin() { return mingap; }
};

#endif
