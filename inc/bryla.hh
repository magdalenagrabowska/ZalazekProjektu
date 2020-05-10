#ifndef BRYLA_HH
#define BRYLA_HH

#include "Wektor3D.hh"
#include "Macierz3D.hh"

class bryla{
protected:
MacierzOb orientacja;
Wektor3D<double,3> srodek;
Wektor3D<double,3> translacja;
double KatOstr=1;
public:
virtual bool obliczwsp()=0;
virtual void zmienp(Wektor3D<double,3> M)=0;
virtual void zmienkat(double KatOstr)=0;
};

#endif