#ifndef PC_H
#define PC_H
#include <vector>


struct coeffSpaceStruct
{
    double min;
    double max;
    int disc;
};

struct coeffVecStruct
{
    double value;
};

struct momVecStruct
{
    double value;
};

struct momSpaceStruct
{
    double min;
    double max;
    int disc;
};

class momVec
{
	private:
	std::vector<momVecStruct> momvec;
	
	public:
	momVec(double p);
	momVec(double p1, double p2);
	momVecStruct get(int Vnum) { return momvec[Vnum]; }
	void update(int num, double value ) { momvec[num].value = value; }
};	

class coeffVec
{
	private:
	std::vector<coeffVecStruct> coeffvec;
	
	public:
	coeffVec( double var1, double var2 );
	coeffVec() {;}
	coeffVecStruct get(int Vnum) { return coeffvec[Vnum]; }
	void resizecoeffVec( int NumOfVar ) { coeffvec.resize( NumOfVar ); }
	void update( int num, double value ) { coeffvec[num].value = value; }
};

class coeffSpace
{
	private:
	std::vector<coeffSpaceStruct> coeffvaryspace;
	std::vector<coeffVecStruct> coeffconstspace;
	
	public:
	coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc);
	coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc, double varConst1);
	coeffSpace( double varAmin, double varAmax, int varAdisc, double varBmin, double varBmax, int varBdisc, double varConst1, double varConst2);
	coeffSpaceStruct getVary(int Vnum) { return coeffvaryspace[Vnum]; }
	coeffVecStruct getConst(int Vnum) { return coeffconstspace[Vnum]; }
	std::vector<coeffSpaceStruct> getWholeVary() { return coeffvaryspace; }
	std::vector<coeffVecStruct> getWholeConst() { return coeffconstspace; }
};

class momSpace
{
	private:
	std::vector<momSpaceStruct> momspace;
	
	public:
	momSpace( double pmin, double pmax, int pdisc );
	momSpace( double p1min, double p1max, double p1disc, double p2min, double p2max, double p2disc);
	momSpaceStruct get(int Vnum) { return momspace[Vnum]; }
};

// Members
#endif

