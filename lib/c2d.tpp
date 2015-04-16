template <class T, class C> void chern2D<T,C>::linspaceP1(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint);
    while(pmin <= pmax+(step/2))
    {
        p1Vec.push_back(pmin);
        pmin += step;
    }
}

template <class T, class C> void chern2D<T,C>::linspaceP2(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint);
    while(pmin <= pmax+(step/2))
    {
        p2Vec.push_back(pmin);
        pmin += step;
    }
}


template <class T, class C> chern2D<T,C>::chern2D( momSpace momS, coeffVec coeffV )
{

	linspaceP1(momS.get(0).min,momS.get(0).max,momS.get(0).disc);
    linspaceP2(momS.get(1).min,momS.get(1).max,momS.get(1).disc);
	momGrid.resize( momS.get(0).disc );
    for ( auto& row : momGrid ) 
	{
        row.reserve( momS.get(1).disc );
    }
	 for(int i = 0; i < momS.get(0).disc; i++)
    {
        for( int j = 0; j < momS.get(1).disc; j++ )
        {
			momVec momV(p1Vec[i],p2Vec[j]);
			C sys(momV, coeffV);
            momGrid[i][j] = sys;
			momGrid[i][j].computeEig();
		}
    }
	
	int HamSize = momGrid[0][0].getHamiltonian().cols();

    ChernN = 0.0;

	if ( HamSize == 2 )
	{
		std::complex<double> A1, A2, A3, A4;
		 for(int i = 0; i < momS.get(0).disc-1; i++)
		{
			for( int j = 0; j < momS.get(1).disc-1; j++ )
			{
				A1 = momGrid[i][j].getEigenvectors().col(0).dot(momGrid[i+1][j].getEigenvectors().col(0));
				A2 = momGrid[i+1][j].getEigenvectors().col(0).dot(momGrid[i+1][j+1].getEigenvectors().col(0));
				A3 = momGrid[i+1][j+1].getEigenvectors().col(0).dot(momGrid[i][j+1].getEigenvectors().col(0));
				A4 = momGrid[i][j+1].getEigenvectors().col(0).dot(momGrid[i][j].getEigenvectors().col(0));
				ChernN += std::arg(A1*A2*A3*A4)/(2*PI);
			}
		}
	}

	if (HamSize > 2)
	{
		Eigen::Matrix2cd C1, C2, C3, C4;	
		for(int i = 0; i < momS.get(0).disc-1; i++)
	    {
		    for( int j = 0; j < momS.get(1).disc-1; j++ )
			{
				for( int k = 0; k < 2; k++)
				{
					for( int l = 0; l < 2; l++)
					{
						C1(k,l) = momGrid[i][j].getEigenvectors().col(k).dot(momGrid[i+1][j].getEigenvectors().col(l));
						C2(k,l) = momGrid[i+1][j].getEigenvectors().col(k).dot(momGrid[i+1][j+1].getEigenvectors().col(l));
						C3(k,l) = momGrid[i+1][j+1].getEigenvectors().col(k).dot(momGrid[i][j+1].getEigenvectors().col(l));
						C4(k,l) = momGrid[i][j+1].getEigenvectors().col(k).dot(momGrid[i][j].getEigenvectors().col(l));
					}
				}
				ChernN += std::arg(C1.determinant()*C2.determinant()*C3.determinant()*C4.determinant())/(2*PI);
			}
		}
	}
    double gaptemp = 100.0;
    for ( int i = 0; i < momS.get(0).disc-1; i++)
    {
        for( int j = 0; j< momS.get(1).disc-1; j++ )
        {
            if ( momGrid[i][j].getGap() < gaptemp )
            {		
                gaptemp = momGrid[i][j].getGap();
            }
        }
    }
    gapmin = gaptemp;
}
