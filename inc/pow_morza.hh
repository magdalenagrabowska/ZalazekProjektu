#ifndef POWIERZCHNIA_MORZA_HH
#define POWIERZCHNIA_MORZA_HH

#include"pow.hh"
#include"Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

class pow_dna:public powierzchnia{
uint denko;
public:
pow_dna(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[4], MacierzOb &orientacja):powierzchnia(Api,translacja,wej,orientacja){
    punkt[0]=Wektor3D(-19,-19,-19);
    punkt[1]=Wektor3D(-19,19,-19);
    punkt[2]=Wektor3D(19,-19,-19);
    punkt[3]=Wektor3D(19,19,-19);
    wej=punkt;
    denko=rysuj();
}
};


class pow_morza:public powierzchnia{
uint powierz;
public:
pow_morza(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[4], MacierzOb &orientacja):powierzchnia(Api,translacja,wej,orientacja){
    punkt[0]=Wektor3D(-19,-19,19);
    punkt[1]=Wektor3D(-19,19,19);
    punkt[2]=Wektor3D(19,-19,19);
    punkt[3]=Wektor3D(19,19,19);
    wej=punkt;
    powierz=rysuj();
}
};

#endif