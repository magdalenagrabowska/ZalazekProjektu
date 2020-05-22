#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "pscian.hh"
#include "Wektor3D.hh"
#include "Macierz3D.hh"

class in_dron{
public:
Wektor3D wej[8];
virtual void przesunieciedronabokl(double a)=0;
virtual void przesuneciedronaprzod(double a)=0;
virtual void przesunieciedronagora(double a)=0;
virtual int obrot(double kat)=0;
};




#endif