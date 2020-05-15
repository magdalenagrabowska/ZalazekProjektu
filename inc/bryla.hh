#ifndef BRYLA_HH
#define BRYLA_HH

#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"


using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class bryla{
protected:
MacierzOb orientacja;
Wektor3D translacja;
std::shared_ptr<drawNS::Draw3DAPI> api;
uint id;
public:
bryla(drawNS::Draw3DAPI *Api, Wektor3D trans, MacierzOb ori): api(Api), translacja(trans), orientacja(ori){}
virtual void rysuj()=0;
virtual void usun(uint dr)=0;
void zmienp(const Wektor3D &M){
     translacja=translacja+M;
}
void zmienkat(double KatOstr){
    MacierzOb obrot(KatOstr);
    orientacja=orientacja*obrot;
}
};

#endif