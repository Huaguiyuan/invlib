#ifndef PSW1D_H
#define PSW1D_H
#include "w1d.h"
#include "pc.h"
#include <vector>
#include <iostream>
#include <fstream>
class phaseSpace1DW
{
    private:
	std::vector<double> varAVec;
	std::vector<double> varBVec;
	
    public:
    phaseSpace1DW( momSpace momS, coeffSpace coeffS);
    void varAlinspace(double varAmin, double varAmax, int varAint);
    void varBlinspace(double varBmin, double varBmax, int varBint);
};

#include "../lib/ps1dw.tpp"

#endif
