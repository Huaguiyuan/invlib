template <class T, class C> void wind3D<T,C>::linspaceP1(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint);
    while(pmin <= pmax+(step/2))
    {
        p1Vec.push_back(pmin);
        pmin += step;
    }
}

template <class T, class C> void wind3D<T,C>::linspaceP2(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint);
    while(pmin <= pmax+(step/2))
    {
        p2Vec.push_back(pmin);
        pmin += step;
    }
}

template <class T, class C> void wind3D<T,C>::linspaceP3(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint);
    while(pmin <= pmax+(step/2))
    {
        p3Vec.push_back(pmin);
        pmin += step;
    }
}

template <class T, class C> wind3D<T,C>::wind3D( momSpace momS, coeffVec coeffV )
{

	linspaceP1( momS.get(0).min,momS.get(0).max,momS.get(0).disc );
    linspaceP2( momS.get(1).min,momS.get(1).max,momS.get(1).disc );
	linspaceP3( momS.get(2).min,momS.get(2).max,momS.get(2).disc );

	momGrid.resize( momS.get(0).disc )
	for( int i = 0; i < momS.get(0).disc ) 
	{
        momGrid[i].resize( momS.get(1).disc );
		for( int j = 0; j < momS.get(1).disc )
		{
			momGrid[i][j].resize( momS.get(2).disc );
			for( int k = 0; k < momS.get(2).disc; k++ )
			{
				momGrid[i][j][k].reserve( 4 );
			}
		}
    }
	
	std::vector<momVec> momPoints;
	momPoints.reserve(4);
	double shift = 1e-6;
	
	for( int i = 0; i < momS.get(0).disc; i++)
    {
        for( int j = 0; j < momS.get(1).disc; j++ )
        {
			for( int k = 0; k < momS.get(2).disc; k++ )
			{
				momPoints[0] = momVec( p1Vec[i], p2Vec[j], p3Vec[k]);
				momPoints[1] = momVec( p1Vec[i] + shift, p2Vec[j], p3Vec[k] );
				momPoints[2] = momVec( p1Vec[i], p2Vec[j] + shift, p3Vec[k] );
				momPoints[4] = momVec( p1Vec[i], p2Vec[j], p3Vec[k] + shift );
				for( int n = 0; n < 4; n++ )
				{
					momGrid[i][j][k][n] = System( momPoints[n], coeffV );
					momGrid[i][j][k][n].computeEig();
				}	
			}
		}
    }
	
	int HamSize = momGrid[0][0][0].getHamiltonian().cols();
	
	WindN = 0.0;
	
	for( int i = 0; i < momS.get(0).disc; i++ )
	{
		for( int j = 0; j < momS.get(1).disc; j++ )
		{
			for( int k = 0; k < momS.get(2).disc; k++ )
			{
				
				
			}
		}
	}

 

}
