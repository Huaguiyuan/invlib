#ifndef W3D_H
#define W3D_H
#include "s.h"
#include "pc.h"
#include <vector>

template<class T, class C = System<T> >
class wind3D
{
	private:
	T HamClass
	std::vector< std::vector< std::vector< std::vector< < < C > > > > momGrid;
	std::vector<double> p1Vec;
	std::vector<double> p2Vec;
	std::vector<double> p3Vec;
	double WindN;
	double gapmin;

	public:
	wind3D( momSpace momS, coeffSpace coeffS );
	void linspaceP1( double pmin, double pmax, double pint );
	void linspaceP2( double pmin, double pmax, double pint );
	void linspaceP3( double pmin, double pmax, double pint );
	double getWind() { return WindN; }
	double getgapmin() { return gapmin; }
};

#include "../lib/w3d.tpp"
#endif
