#include "../include/pc.h"
#include <vector>

momVec::momVec( double p )
{
	momvec.resize(1);
	momvec[0].value = p;	
} 

momVec::momVec( double p1, double p2 )
{
	momvec.resize(2);
	momvec[0].value = p1;
	momvec[1].value = p2;
} 


coeffVec::coeffVec( double var1, double var2 )
{
	coeffvec.resize(2);
	coeffvec[0].value = var1;
	coeffvec[1].value = var2;
}


coeffSpace::coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc)
{
	coeffvaryspace.resize(2);
	coeffvaryspace[0].min = varAmin;
	coeffvaryspace[0].max = varAmax;
	coeffvaryspace[0].disc = varAdisc;	
	coeffvaryspace[1].min = varBmin;
	coeffvaryspace[1].max = varBmax;
	coeffvaryspace[1].disc = varBdisc;
}

coeffSpace::coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc, double var1Const)
{
	coeffvaryspace.resize(2);
	coeffvaryspace[0].min = varAmin;
	coeffvaryspace[0].max = varAmax;
	coeffvaryspace[0].disc = varAdisc;	
	coeffvaryspace[1].min = varBmin;
	coeffvaryspace[1].max = varBmax;
	coeffvaryspace[1].disc = varBdisc;
	coeffconstspace.resize(1);
	coeffconstspace[0].value = var1Const;
}

coeffSpace::coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc, double var1Const, double var2Const)
{
	coeffvaryspace.resize(2);
	coeffvaryspace[0].min = varAmin;
	coeffvaryspace[0].max = varAmax;
	coeffvaryspace[0].disc = varAdisc;	
	coeffvaryspace[1].min = varBmin;
	coeffvaryspace[1].max = varBmax;
	coeffvaryspace[1].disc = varBdisc;
	coeffconstspace.resize(2);
	coeffconstspace[0].value = var1Const;
	coeffconstspace[1].value = var2Const;
}

momSpace::momSpace( double pmin, double pmax, int pdisc )
{
	momspace.resize(1);
	momspace[0].min = pmin;
	momspace[0].max = pmax;
	momspace[0].disc = pdisc;
}

momSpace::momSpace( double p1min, double p1max, double p1disc, double p2min, double p2max, double p2disc)
{
	momspace.resize(2);
	momspace[0].min = p1min;
	momspace[0].max = p1max;
	momspace[0].disc = p1disc;
	momspace[1].min = p2min;
	momspace[1].max = p2max;
	momspace[1].disc = p2disc;
}

