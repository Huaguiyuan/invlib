#ifndef S_H
#define S_H
#include "pc.h"
#include "user.h"
#include "pauc.h"
#include <complex>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Eigenvalues>
#include <iostream>


typedef Eigen::Matrix<std::complex<double>,8,8> Matrix8cd;
typedef Eigen::Matrix<double,8,1> Vector8d;
typedef Eigen::Matrix<std::complex<double>,8,1> Vector8cd;

struct Ham2x2
{
	Eigen::Matrix2cd hamiltonian;
    Eigen::Vector2d eigenvalues;
    Eigen::Matrix2cd eigenvectors;
    Eigen::Vector3d sVec;
};

struct Ham4x4
{
	Eigen::Matrix4cd hamiltonian;
    Eigen::Vector4d eigenvalues;
    Eigen::Matrix4cd eigenvectors;
	Eigen::Vector3d sVec;
};

struct Ham8x8
{
	Matrix8cd hamiltonian;
    Vector8d eigenvalues;
    Matrix8cd eigenvectors;
	Eigen::Vector3d sVec;
};

template <class T>
class System
{
    private:
    T HamContainer;
    double gap;

    public:
    System(momVec momV, coeffVec coeffV);
    void computeEig();
    auto getHamiltonian() { return HamContainer.hamiltonian; }
    auto getEigenvectors() { return HamContainer.eigenvectors; }
    auto getEigenvalues() { return HamContainer.eigenvalues; }
    Eigen::Vector3d getsVec() { return HamContainer.sVec; }
	double getGap() { return gap; }
	void CheckHermiticity();
}; 

#include "../lib/s.tpp"
#endif
