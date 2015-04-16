template< class T, class C >
void phaseSpace2DC<T,C>::varAlinspace(double varAmin, double varAmax, int varAint)
{
    double step = (varAmax-varAmin) / (varAint-1);
    while(varAmin <= varAmax)
    {
        varAVec.push_back(varAmin);
        varAmin += step;
    }
}

template< class T, class C >
void phaseSpace2DC<T,C>::varBlinspace(double varBmin, double varBmax, int varBint)
{
    double step = (varBmax-varBmin) / (varBint-1);
    while(varBmin <= varBmax)
    {
        varBVec.push_back(varBmin);
        varBmin += step;
    }
}

template< class T, class C > phaseSpace2DC<T,C>::phaseSpace2DC( momSpace momS, coeffSpace coeffS)
{
 	int NumOfVar = coeffS.getWholeVary().size() + coeffS.getWholeConst().size();

	double varAmin = coeffS.getVary(0).min;
	double varAmax = coeffS.getVary(0).max;
	int varAdisc = coeffS.getVary(0).disc;
	double varBmin = coeffS.getVary(1).min;
	double varBmax = coeffS.getVary(1).max;
	int varBdisc = coeffS.getVary(1).disc; 
	
    varAlinspace( varAmin, varAmax , varAdisc );
    varBlinspace( varBmin, varBmax , varBdisc );

	coeffVec coeffV;
	coeffV.resizecoeffVec( NumOfVar );
	if ( NumOfVar > 2 )
	{
		for (unsigned int i = 0; i < coeffS.getWholeConst().size(); i++)
		{
			coeffV.update(2+i,coeffS.getConst(i).value);
		}
	}
	

    std::ofstream myfile;
    myfile.open ("OUTPUT.dat");
    for(int i = 0; i < varAdisc; i++)
    {
        for(int j = 0; j < varBdisc; j++)
        {
            coeffV.update(0, varAVec[i]);
            coeffV.update(1, varBVec[j]);
            C Space(momS, coeffV);
            myfile <<  coeffV.get(0).value << " " << coeffV.get(1).value << " " << Space.getChern() << std::endl; 
			std::cout << " Progress: " << 100.0*(double(i) * double(varBdisc) + double(j))/(double(varAdisc) * double(varBdisc)) << "%        " << '\r';
			std::cout.flush();
        }
    }
    myfile.close();
}
