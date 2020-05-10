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
virtual void obliczwsp()=0;
virtual void zmienp(const Wektor3D<double,3> &M)=0;
virtual void zmienkat(const double KatOstr)=0;
};

#endif