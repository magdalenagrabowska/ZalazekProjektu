#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"


class dron:public in_dron,public pscian{
public:
uint iden=1;
dron(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8], MacierzOb &orientacja):pscian(Api,translacja,wej,orientacja){
   _Wierz_lok[0]=Wektor3D(-3,0,0);
    _Wierz_lok[1]=Wektor3D(-3,2,0);
    _Wierz_lok[2]=Wektor3D(1,2,0);
    _Wierz_lok[3]=Wektor3D(1,0,0);
    _Wierz_lok[4]=Wektor3D(-3,0,3);
    _Wierz_lok[5]=Wektor3D(-3,2,3);
    _Wierz_lok[6]=Wektor3D(1,2,3);
    _Wierz_lok[7]=Wektor3D(1,0,3);
     wej=_Wierz_lok;
     iden=rysuj();
}
void wait4key();
void przesunieciedronabokl(double a)override;
void przesuneciedronaprzod(double a)override;
void przesunieciedronagora(double a)override;
void obrot(double kat);

};



#endif