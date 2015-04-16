#include "../include/w1d.h"
#include <vector>
#include <iostream>

void wind1D::linspace(double pmin, double pmax, int pint)
{
    double step = (pmax-pmin) / (pint-1);
    double shift = 1e-6;

    while(pmin <= pmax)
    {
        pVec.push_back(pmin);
        pVecShift.push_back(pmin+shift);
        pmin += step;
    }
}


wind1D::wind1D( momSpace momS, coeffVec coeffV )
{
    linspace(momS.get(0).min,momS.get(0).max,momS.get(0).disc);
    double shift = 1e-6;
    windN = 0;
    Eigen::Vector3d temp, tempShift, dsVec, crossed, normV;
    double windPart;
    double windTemp;
    double gaptemp = 100.0;

    momVec momV(0.0);
    momVec momVShift(0.0);


    for( int i = 0; i < momS.get(0).disc-1; i++)
    {
        //std::cout << "loop: " << i << "\n";
        momV.update(0,pVec[i]);
        momVShift.update(0,pVecShift[i]);
        System<Ham2x2> system(momV, coeffV);
        System<Ham2x2> systemShift(momVShift, coeffV);
        system.computeEig();
        systemShift.computeEig();
        temp = system.getsVec();
        tempShift = systemShift.getsVec();
        dsVec = (tempShift - temp)/shift;
        crossed = temp.cross(dsVec);
        normV(0) = std::abs(crossed(0)/(crossed.norm() + 1e-5));
        normV(1) = std::abs(crossed(1)/(crossed.norm() + 1e-5));
        normV(2) = std::abs(crossed(2)/(crossed.norm() + 1e-5));
        windPart = crossed.dot(normV);
        windTemp += windPart;
        if ( system.getGap() < gaptemp )
        {
            gaptemp = system.getGap();
        }
    }

    windN = windTemp/momS.get(0).disc;

    mingap = gaptemp;
}
