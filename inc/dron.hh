#ifndef DRON_HH
#define DRON_HH

#include "interfejs_drona.hh"
#include "pscian.hh"
#include "wirniki.hh"
#include "Macierz3D.hh"

class dron:public in_dron,public pscian{
public:
wirnik prawus;
wirnik lewus;
uint iden=1;
dron(drawNS::APIGnuPlot3D *Api, Wektor3D &transformacja,Wektor3D wej[8],Wektor3D wirusl[12],Wektor3D wirusp[12],MacierzOb &orientacja):pscian(Api,transformacja,wej,orientacja),lewus(Api,transformacja,wirusl,orientacja),prawus(Api,transformacja,wirusp,orientacja){
    _Wierz_lok[0]=Wektor3D(-3,0,0);  wirusl[0]=Wektor3D(-3,0,1.5);
    _Wierz_lok[1]=Wektor3D(-3,2,0);   wirusl[1]=Wektor3D(-2.5,0,2) ;
   _Wierz_lok[2]=Wektor3D(1,2,0);     wirusl[2]=Wektor3D(-1.5,0,2);
   _Wierz_lok[3]=Wektor3D(1,0,0);     wirusl[3]=Wektor3D(-1,0,1.5) ;
   _Wierz_lok[4]=Wektor3D(-3,0,3);   wirusl[4]=Wektor3D(-1.5,0,1);
  _Wierz_lok[5]=Wektor3D(-3,2,3);    wirusl[5]=Wektor3D(-2.5,0,1) ;
   _Wierz_lok[6]=Wektor3D(1,2,3);    wirusl[6]=Wektor3D(-3,-2,1.5);
 _Wierz_lok[7]=Wektor3D(1,0,3);  
                                     wirusl[7]=Wektor3D(-2.5,-2,2) ;
                                   wirusl[8]=Wektor3D(-1.5,-2,2);
                                     wirusl[9]=Wektor3D(-1,-2,1.5) ;
                                    wirusl[10]=Wektor3D(-1.5,-2,1);
                                      wirusl[11]=Wektor3D(-2.5,-2,1) ;
   wirusp[0]=Wektor3D(-1,0,1.5);
   wirusp[1]=Wektor3D(-0.5,0,2) ;
   wirusp[2]=Wektor3D(0.5,0,2);
   wirusp[3]=Wektor3D(1,0,1.5) ;
   wirusp[4]=Wektor3D(0.5,0,1);
   wirusp[5]=Wektor3D(-0.5,0,1) ;
   wirusp[6]=Wektor3D(-1,-2,1.5);
   wirusp[7]=Wektor3D(-0.5,-2,2) ;
   wirusp[8]=Wektor3D(0.5,-2,2);
   wirusp[9]=Wektor3D(1,-2,1.5) ;
   wirusp[10]=Wektor3D(0.5,-2,1);
   wirusp[11]=Wektor3D(-0.5,-2,1);
} 
void wait4key();
void przesunieciedronabokl(double a)override;
void przesuneciedronaprzod(double a)override;
void przesunieciedronagora(double a)override;
void obrot(double kat);
uint rysuj();
};



#endif