//#include "s.h"
#include "../include/pc.h"
//#include "w1d.h"
//#include "ps1dw.h"
#include "../include/psc2d.h"
#include <iostream>
#include "../include/c2d.h"
#define PI 3.14159


int main()
{
#if 0
	momVec momV(-PI,PI);
	coeffVec coeffV(-2.0,2.0);   
 	System<Ham4x4> mySystem(momV, coeffV);
   	mySystem.computeEig();
	mySystem.CheckHermiticity();
   	std::cout << mySystem.getEigenvectors() << std::endl;
#endif

#if 0
	momSpace momS(-PI,PI,100,-PI,PI,100);
	coeffVec coeffV(1.0,3.0);
	chern2D<Ham4x4> test(momS, coeffV);
	std::cout << test.getChern() << std::endl;
#endif

#if 0
	momSpace momS(-PI,PI,20,-PI,PI,20);
	coeffSpace coeffS(0.0,6.0,50,0.0,4.0,50);
	phaseSpace2DC<Ham4x4> test(momS, coeffS);
#endif

#if 0
	momSpace momS(-PI,PI,50,-PI,PI,50);
	coeffVec coeffV(3.0,3.0);
	chern2D<Ham4x4> test(momS,coeffV);
#endif

#if 1
	momSpace momS(-PI,PI,5,-PI,PI,5);
	coeffSpace coeffS(-3.0,3.0,300,0.0,6.0,300,0.0,1.0);
	phaseSpace2DC<Ham4x4> test(momS,coeffS);
#endif

#if 0
	momSpace momS(-PI,PI,5,-PI,PI,5);
	coeffSpace coeffS(-PI,PI,100,-6.0,6.0,100,1.0);
	phaseSpace2DC<Ham2x2> test(momS,coeffS);
#endif

#if 0
	momSpace momS(-PI,PI,100);
	coeffSpace coeffS(-2.0,2.0,30,-2.0,2.0,30);
	phaseSpace1DW(momS,coeffS);
#endif
	return 0;
}

