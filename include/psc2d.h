#ifndef PSC2D_H
#define PSC2D_H
#include "c2d.h"
#include "pc.h"
#include <vector>
#include <fstream>
template< class T, class C = chern2D<T> >
class phaseSpace2DC
{
    private:
	std::vector<double> varAVec;
	std::vector<double> varBVec;
	
    public:
    phaseSpace2DC( momSpace momS, coeffSpace coeffS);
    void varAlinspace(double varAmin, double varAmax, int varAint);
    void varBlinspace(double varBmin, double varBmax, int varBint);
};

#include "../lib/psc2d.tpp"
#endif
