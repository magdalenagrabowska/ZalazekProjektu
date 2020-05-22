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
int id=-1;
public:
bryla(drawNS::Draw3DAPI *Api, Wektor3D trans, MacierzOb ori): api(Api), translacja(trans), orientacja(ori){}
virtual int rysuj()=0;
void zmienp(const Wektor3D &M){
     translacja=translacja+M;
}
void zmienkaty(double KatOstr){
    MacierzOb obrot;
    obrot.macobry(KatOstr);
    orientacja=orientacja*obrot;
}
void zmienkatz(double KatOstr){
    MacierzOb obrot; 
    obrot.macobrz(KatOstr);
    orientacja=orientacja*obrot;
}
};

#endif