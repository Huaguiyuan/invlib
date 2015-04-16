#include "../include/user.h"
#include "../include/pc.h"   
#include <iostream>
#include <vector>


std::complex<double> hamElements(int i, int j, momVec momV, coeffVec coeffV )
{
    std::vector<std::vector<std::complex<double> > > HamElements;
    HamElements.resize(8);
    for ( int k = 0; k < 8; k++ ) { HamElements[k].reserve(8); }
    std::complex<double> I(0.0,1.0); // This is the imaginary unit for use below.

#if 0	
    ////////////////////////////////////////////////////
    // Assign variable names here.
    // Define as many as required.
    // Coefficients are contained in the coeffVec class objects.
    // Momentum parameters are contained in the momVec class objects.
    // If using the phaseSpace class, the elements of coeffV are 
    // ordered the same as in the coeffSpace constructor in your 
    // main.cpp
    double mu = coeffV.get(0).value;
    double delta = coeffV.get(1).value;
    double p = momV.get(0).value;
    ////////////////////////////////////////////////////
	
    ////////////////////////////////////////////////////
    // Assign function elements of the Hamiltonian here.
    // For larger Hamiltonians add more terms.
    HamElements[0][0] = mu - cos( p );
    HamElements[0][1] = I * delta * sin( p );
    HamElements[1][0] = std::conj(HamElements[0][1]);
    HamElements[1][1] = -HamElements[0][0];
#endif
    ////////////////////////////////////////////////////
#if 0
	//2D 2 Species Superconductor
	
	double mu = coeffV.get(0).value;
	double delta = coeffV.get(1).value;
	double px = momV.get(0).value;
	double py = momV.get(1).value;	
	
	
	HamElements[0][0] = mu + delta + 2.0 * cos( py );
	HamElements[0][1] = I * (1.0 + exp( -I * px ));
	HamElements[0][2] = I * sin ( py );
	HamElements[0][3] = 2.0 * (1.0 - exp( -I * px ));
	HamElements[1][0] = std::conj(HamElements[0][1]);
	HamElements[1][1] = mu - delta + 2.0 * cos( py );
	HamElements[1][2] = -2.0 * (1.0 - exp( I * px ));
	HamElements[1][3] = HamElements[0][2];
	HamElements[2][0] = std::conj(HamElements[0][2]);
	HamElements[2][1] = std::conj(HamElements[1][2]);
	HamElements[2][2] = -HamElements[0][0];
	HamElements[2][3] = HamElements[0][1];
	HamElements[3][0] = std::conj(HamElements[0][3]);
	HamElements[3][1] = std::conj(HamElements[1][3]);
	HamElements[3][2] = std::conj(HamElements[2][3]);
	HamElements[3][3] = -HamElements[1][1];
#endif

#if 1 
	//Staggered Haldane Model
	double delta = coeffV.get(0).value;
	double phi = coeffV.get(1).value;
	double mu = coeffV.get(2).value;
	double t = coeffV.get(3).value;
	double px = momV.get(0).value;
	double py = momV.get(1).value;	
	
	HamElements[0][0] = mu + delta + 2.0 * t * cos( px + phi );
	HamElements[0][1] = t * (1.0 + exp( I * px ));
	HamElements[0][2] = t * (exp( -I * phi ) * (exp( I * px ) + exp( I * py )) + exp( I * phi ) + exp( -I * (px - py - phi))); 
	HamElements[0][3] = t * exp( I * py );
	HamElements[1][0] = std::conj(HamElements[0][1]);
	HamElements[1][1] = mu + delta + 2.0 * t * cos( px - phi );
	HamElements[1][2] = t;
	HamElements[1][3] = t * (exp( I * phi ) * (exp( I * px ) + exp( I * py )) + exp( I * phi ) + exp( -I * (px - py + phi)));
	HamElements[2][0] = std::conj(HamElements[0][2]);
	HamElements[2][1] = std::conj(HamElements[1][2]);
	HamElements[2][2] = mu - delta + 2.0 * t * cos( px + phi );
	HamElements[2][3] = HamElements[0][1];
	HamElements[3][0] = std::conj(HamElements[0][3]);
	HamElements[3][1] = std::conj(HamElements[1][3]);
	HamElements[3][2] = std::conj(HamElements[2][3]);
	HamElements[3][3] = mu - delta + 2.0 * t * cos( px - phi );
#endif

#if 0
	double phi = coeffV.get(0).value;
	double mu = coeffV.get(1).value;
	double t = coeffV.get(2).value;
	double px = momV.get(0).value;
	double py = momV.get(1).value;	
	
	HamElements[0][0] = mu/(2.0 * t) + cos( py - phi) + cos( px + phi ) + cos( px - py - phi );
	HamElements[0][1] = 0.5 * (1.0 + exp( I * py ) + exp( I * px ));
	HamElements[1][0] = std::conj(HamElements[0][1]); 
	HamElements[1][1] = -mu/(2.0 * t) + cos( py + phi) + cos( px - phi ) + cos( px - py + phi );
#endif
	return HamElements[i][j];
}
