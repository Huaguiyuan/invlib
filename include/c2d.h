#ifndef C2D_H
#define C2D_H
#include "s.h"
#include "pc.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#define PI 3.14159

template <class T, class C = System<T>>
class chern2D
{
    private:
    T HamClass;
	std::vector<std::vector<C> > momGrid;
	std::vector<double> p1Vec;
    std::vector<double> p2Vec;
    double ChernN;
    double gapmin;

    public:
    chern2D( momSpace momS, coeffVec coeffV );
    void linspaceP1(double pmin, double pmax, int pint);
    void linspaceP2(double pmin, double pmax, int pint);
    double getChern() { return ChernN; }
    double getgapmin() { return gapmin; }
};

#include "../lib/c2d.tpp"

#endif
