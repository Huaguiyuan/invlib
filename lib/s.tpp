template <class T> System<T>::System(momVec momV, coeffVec coeffV)
{
	int HamSize = HamContainer.hamiltonian.cols();
    for (int i = 0; i < HamSize; i++)
    {
        for (int j = 0; j < HamSize; j++)
        {
            HamContainer.hamiltonian(i,j) = hamElements(i, j, momV, coeffV);
        }
	} 
}

template <class T> void System<T>::computeEig()
{
  	 
	int HamSize = HamContainer.hamiltonian.cols();
	
	if (HamSize == 2)
	{
		
		Eigen::Matrix2cd HamTest2;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				HamTest2(i,j) = HamContainer.hamiltonian(i,j);
			}
		}
		typedef Eigen::Matrix2cd A;
		typedef Eigen::Vector2d B;
		typedef Eigen::Vector2cd C;
		Eigen::ComplexEigenSolver<A> ces(HamTest2);
		C eigenvaltemp = ces.eigenvalues();
		B sorteigenvaltemp;

		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}

		B refer;
		for (int i = 0; i < HamSize; i++)
		{
			refer[i] = i;
		}

		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}

		int flag = 1;
		double tempeva, temprefer;
		for ( int i = 0; (i < HamSize) && flag; i++)
		{
			flag = 0;
			for (int j = 0; j < HamSize-1; j++)
			{
				if (sorteigenvaltemp[j+1] < sorteigenvaltemp[j])
				{
					tempeva = sorteigenvaltemp[j];
					sorteigenvaltemp[j] = sorteigenvaltemp[j+1];
					sorteigenvaltemp[j+1] = tempeva;
					temprefer = refer[j];
					refer[j] = refer[j+1];
					refer[j+1] = temprefer;
					flag = 1;
				}
			}
		}
		
		for (int k = 0; k < HamSize; k++)
		{
			HamContainer.eigenvectors.col(k) << ces.eigenvectors().col(refer[k]);
		}

		for ( int i = 0; i < 2; i++ )
		{
			HamContainer.eigenvalues[i] = sorteigenvaltemp[i];
		}
		Eigen::Vector2cd temp;
		for ( int i = 0; i < 2; i++ )
		{
			temp[i] = HamContainer.eigenvectors.col(0)[i];	
		}
		
		HamContainer.sVec(0) = std::real(temp.dot(pauli(1).output() * temp));
		HamContainer.sVec(1) = std::real(temp.dot(pauli(2).output() * temp));
		HamContainer.sVec(2) = std::real(temp.dot(pauli(3).output() * temp));
    
		gap = HamContainer.eigenvalues[HamSize/2] - HamContainer.eigenvalues[(HamSize/2)-1];
	}

	if (HamSize == 4)
	{
		Eigen::Matrix4cd HamTest4;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				HamTest4(i,j) = HamContainer.hamiltonian(i,j);
			}
		}
		typedef Eigen::Matrix4cd A;
		typedef Eigen::Vector4d B;
		typedef Eigen::Vector4cd C;
		//std::cout << HamTest4 << std::endl;
		Eigen::ComplexEigenSolver<A> ces(HamTest4);
		C eigenvaltemp = ces.eigenvalues();
		B sorteigenvaltemp;
		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}
		//std::cout << sorteigenvaltemp;
		B refer;
		for (int i = 0; i < HamSize; i++)
		{
			refer[i] = i;
		}

		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}

		int flag = 1;
		double tempeva, temprefer;
		for ( int i = 0; (i < HamSize) && flag; i++)
		{
			flag = 0;
			for (int j = 0; j < HamSize-1; j++)
			{
				if (sorteigenvaltemp[j+1] < sorteigenvaltemp[j])
				{
					tempeva = sorteigenvaltemp[j];
					sorteigenvaltemp[j] = sorteigenvaltemp[j+1];
					sorteigenvaltemp[j+1] = tempeva;
					temprefer = refer[j];
					refer[j] = refer[j+1];
					refer[j+1] = temprefer;
					flag = 1;
				}
			}
		}
		
		for (int k = 0; k < HamSize; k++)
		{
			HamContainer.eigenvectors.col(k) << ces.eigenvectors().col(refer[k]);
		}
		//std::cout << HamContainer.eigenvectors << std::endl;	
		for (int i = 0; i < 4; i++)
		{	
			HamContainer.eigenvalues[i] = sorteigenvaltemp[i];
		}	

    	gap = HamContainer.eigenvalues[HamSize/2] - HamContainer.eigenvalues[(HamSize/2)-1];
	}

	if (HamSize == 8)
	{
		Matrix8cd HamTest8;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				HamTest8(i,j) = HamContainer.hamiltonian(i,j);
			}
		}
		typedef Matrix8cd A;
		typedef Vector8d B;
		typedef Vector8cd C;
		Eigen::ComplexEigenSolver<A> ces(HamTest8);
		C eigenvaltemp = ces.eigenvalues();
		B sorteigenvaltemp;

		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}

		B refer;
		for (int i = 0; i < HamSize; i++)
		{
			refer[i] = i;
		}

		for (int i = 0; i < HamSize; i++)
		{
			sorteigenvaltemp[i] = std::real(eigenvaltemp[i]);
		}

		int flag = 1;
		double tempeva, temprefer;
		for ( int i = 0; (i < HamSize) && flag; i++)
		{
			flag = 0;
			for (int j = 0; j < HamSize-1; j++)
			{
				if (sorteigenvaltemp[j+1] < sorteigenvaltemp[j])
				{
					tempeva = sorteigenvaltemp[j];
					sorteigenvaltemp[j] = sorteigenvaltemp[j+1];
					sorteigenvaltemp[j+1] = tempeva;
					temprefer = refer[j];
					refer[j] = refer[j+1];
					refer[j+1] = temprefer;
					flag = 1;
				}
			}
		}
		
		for (int k = 0; k < HamSize; k++)
		{
			HamContainer.eigenvectors.col(k) << ces.eigenvectors().col(refer[k]);
		}

		for ( int i = 0; i < 8; i++ )
		{
			HamContainer.eigenvalues[i] = sorteigenvaltemp[i]; 
		}
		gap = HamContainer.eigenvalues[HamSize/2] - HamContainer.eigenvalues[(HamSize/2)-1];
	}
}

template <class T> void System<T>::CheckHermiticity()
{
	int HamSize = HamContainer.hamiltonian.cols();
	std::complex<double> HTVAL;
	for (int i = 0; i < HamSize; i++)
	{
		for (int j = 0; j < HamSize; j++)
		{
			HTVAL = HamContainer.hamiltonian(i,j)-std::conj(HamContainer.hamiltonian(j,i));
			if ((std::real(HTVAL) != 0.0) && (std::imag(HTVAL) != 0.0))
			{
				std::cout << "Your Hamiltonian is not Hermitian" << std::endl;
				return;
			}					
		}
	}
	std::cout << "Your Hamiltonian is Hermitian" << std::endl;
}
